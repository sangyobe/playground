#define MCAP_COMPRESSION_NO_LZ4
#define MCAP_COMPRESSION_NO_ZSTD
#define MCAP_IMPLEMENTATION
#include "mcap/mcap.hpp"
#include "BuildFileDescriptorSet.h"
#include "LeoQuad.pb.h"
#include <iostream>
#include <fstream>
#include <chrono>

#define NS_PER_MS 1000000
#define NS_PER_S 1000000000

int main()
{
    std::cout << "hello, mcap!\n";


    mcap::McapWriter writer;
    {
        auto options = mcap::McapWriterOptions("");
        const auto res = writer.open("output.mcap", options);
        if (!res.ok()) {
            std::cerr << "Failt to open output.mcap for writing: " << res.message << std::endl;
            return 1;
        }
    }

    mcap::ChannelId channelId;
    {

        // add schema
        mcap::Schema schema(
            "dtproto::leoquad::LeoQuadStateTimeStamped", 
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

    mcap::Timestamp startTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
                                std::chrono::system_clock::now().time_since_epoch())
                                .count();

    for (uint32_t frameIndex = 0; frameIndex < 100; ++frameIndex)
    {
        mcap::Timestamp cloudTime = startTime + (static_cast<uint64_t>(frameIndex) * 100 * NS_PER_MS);

        auto timestamp = LQState.mutable_header()->mutable_time_stamp();
        timestamp->set_seconds(static_cast<int64_t>(cloudTime) / NS_PER_S);
        timestamp->set_nanos(static_cast<int>(cloudTime % NS_PER_S));


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

    writer.close();


    return 0;
}