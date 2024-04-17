#define MCAP_COMPRESSION_NO_LZ4
#define MCAP_COMPRESSION_NO_ZSTD
#define MCAP_IMPLEMENTATION
#include "mcap/mcap.hpp"
#include "BuildFileDescriptorSet.h"
#include "LeoQuad.pb.h"
#include "foxglove/PointCloud.pb.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

#define NS_PER_MS 1000000
#define NS_PER_S 1000000000

#define POINTS_PER_CLOUD 1000
#define FIELDS_PER_POINT 3

class PointGenerator {
private:
  std::mt19937 _generator;
  std::uniform_real_distribution<float> _distribution;

public:
  PointGenerator(uint32_t seed = 0)
      : _generator(seed)
      , _distribution(0.0, 1.0) {}

  // next produces a random point on the unit sphere, scaled by `scale`.
  std::tuple<float, float, float> next(float scale) {
    float theta = 2 * static_cast<float>(M_PI) * _distribution(_generator);
    float phi = acos(1.f - (2.f * _distribution(_generator)));
    float x = float((sin(phi) * cos(theta)) * scale);
    float y = float((sin(phi) * sin(theta)) * scale);
    float z = float(cos(phi) * scale);
    return {x, y, z};
  }
};

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <output.mcap>" << std::endl;
        return 1;
    }
    const char* outputFilename = argv[1];


    mcap::McapWriter writer;
    {
        auto options = mcap::McapWriterOptions("");
        const auto res = writer.open(outputFilename, options);
        if (!res.ok()) {
            std::cerr << "Failt to open " << outputFilename << " for writing: " << res.message << std::endl;
            return 1;
        }
    }

    mcap::ChannelId channelId;
    {

        // add schema
        mcap::Schema schema(
            "dtproto.leoquad.LeoQuadStateTimeStamped", 
            "protobuf", 
            foxglove::BuildFileDescriptorSet(dtproto::leoquad::LeoQuadStateTimeStamped::descriptor()).SerializeAsString());
        writer.addSchema(schema);

        // add channel(topic)
        mcap::Channel channel("LeoQuadState", "protobuf", schema.id);
        writer.addChannel(channel);
        channelId = channel.id;
    }

    dtproto::leoquad::LeoQuadStateTimeStamped LQState;
    {
    }


    mcap::ChannelId channelId_pc;
    {
        // protobuf schemas in MCAP are represented as a serialized FileDescriptorSet.
        // You can use the method in BuildFileDescriptorSet to generate this at runtime,
        // or generate them ahead of time with protoc:
        //   protoc --include_imports --descriptor_set_out=filename your_type.proto
        mcap::Schema schema_pc(
            "foxglove.PointCloud", "protobuf",
            foxglove::BuildFileDescriptorSet(foxglove::PointCloud::descriptor()).SerializeAsString());
        writer.addSchema(schema_pc);

        // choose an arbitrary topic name.
        mcap::Channel channel_pc("pointcloud", "protobuf", schema_pc.id);
        writer.addChannel(channel_pc);
        channelId_pc = channel_pc.id;
    }

    foxglove::PointCloud pcl;
    {
        // Describe the data layout to the consumer of the pointcloud. There are 3 single-precision
        // float fields per point.
        pcl.set_point_stride(sizeof(float) * FIELDS_PER_POINT);
        const char* const fieldNames[] = {"x", "y", "z"};
        int fieldOffset = 0;
        for (const auto& name : fieldNames) {
            auto field = pcl.add_fields();
            field->set_name(name);
            field->set_offset(fieldOffset);
            field->set_type(foxglove::PackedElementField_NumericType_FLOAT32);
            fieldOffset += sizeof(float);
        }
        // Reserve enough space for all of our points.
        pcl.mutable_data()->append(POINTS_PER_CLOUD * FIELDS_PER_POINT * sizeof(float), '\0');

        // Position the pointcloud in 3D space. the "frame_id" identifies the coordinate frame
        // of this pointcloud, and the "pose" determines the pointcloud's position relative to that
        // coordinate frame's center.
        // Here there is only one coordinate frame, so any frame_id string can be used.
        pcl.set_frame_id("pointcloud");

        // Position the pointclouds in the center of their coordinate frame.
        auto* pose = pcl.mutable_pose();
        auto* position = pose->mutable_position();
        position->set_x(0);
        position->set_y(0);
        position->set_z(0);
        auto* orientation = pose->mutable_orientation();
        orientation->set_x(0);
        orientation->set_y(0);
        orientation->set_z(0);
        orientation->set_w(1);
    }



    mcap::Timestamp startTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
                                std::chrono::system_clock::now().time_since_epoch())
                                .count();

    for (uint32_t frameIndex = 0; frameIndex < 100; ++frameIndex)
    {
        mcap::Timestamp cloudTime = startTime + (static_cast<uint64_t>(frameIndex) * 100 * NS_PER_MS);
        
        auto timestamp = LQState.mutable_header()->mutable_time_stamp();
        timestamp->set_seconds(static_cast<int64_t>(cloudTime) / NS_PER_S);
        timestamp->set_nanos(static_cast<int>(cloudTime % NS_PER_S));
        LQState.mutable_header()->set_seq(frameIndex);


        std::string serialized = LQState.SerializeAsString();
        mcap::Message msg;
        msg.channelId = channelId;
        msg.sequence = frameIndex;
        msg.publishTime = cloudTime;
        msg.logTime = cloudTime;
        msg.data = reinterpret_cast<const std::byte*>(serialized.data());
        msg.dataSize = serialized.size();
        const auto res = writer.write(msg);
        if (!res.ok()) {
            std::cerr << "Failed to write message: " << res.message << "\n";
            writer.terminate();
            writer.close();
            //std::ignore = std::remove(outputFilename);
            return 1;
        }
    }

    PointGenerator pointGenerator;
    // write 100 pointcloud messages into the output MCAP file.
    for (uint32_t frameIndex = 0; frameIndex < 100; ++frameIndex) 
    {
        // Space these frames 100ms apart in time.
        mcap::Timestamp cloudTime = startTime + (static_cast<uint64_t>(frameIndex) * 100 * NS_PER_MS);
        // Slightly increase the size of the cloud on every frame.
        float cloudScale = 1.f + (static_cast<float>(frameIndex) / 50.f);

        auto timestamp = pcl.mutable_timestamp();
        timestamp->set_seconds(static_cast<int64_t>(cloudTime) / NS_PER_S);
        timestamp->set_nanos(static_cast<int>(cloudTime % NS_PER_S));

        // write 1000 points into each pointcloud message.
        size_t offset = 0;
        for (int pointIndex = 0; pointIndex < POINTS_PER_CLOUD; ++pointIndex) 
        {
            auto [x, y, z] = pointGenerator.next(cloudScale);
            char* data = pcl.mutable_data()->data();
            std::memcpy(&data[offset], reinterpret_cast<const char*>(&x), sizeof(x));
            offset += sizeof(x);
            std::memcpy(&data[offset], reinterpret_cast<const char*>(&y), sizeof(y));
            offset += sizeof(y);
            std::memcpy(&data[offset], reinterpret_cast<const char*>(&z), sizeof(z));
            offset += sizeof(z);
        }
        std::string serialized = pcl.SerializeAsString();
        // Include the pointcloud data in a message, then write it into the MCAP file.
        mcap::Message msg;
        msg.channelId = channelId_pc;
        msg.sequence = frameIndex;
        msg.publishTime = cloudTime;
        msg.logTime = cloudTime;
        msg.data = reinterpret_cast<const std::byte*>(serialized.data());
        msg.dataSize = serialized.size();
        const auto res = writer.write(msg);
        if (!res.ok()) {
            std::cerr << "Failed to write message: " << res.message << "\n";
            writer.terminate();
            writer.close();
            // std::ignore = std::remove(outputFilename);
            return 1;
        }
    }

    writer.close();


    return 0;
}