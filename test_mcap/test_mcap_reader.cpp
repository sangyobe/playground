#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/descriptor_database.h>
#include <google/protobuf/dynamic_message.h>

#define MCAP_COMPRESSION_NO_LZ4
#define MCAP_COMPRESSION_NO_ZSTD
#define MCAP_IMPLEMENTATION
// #include "mcap/mcap.hpp"
#include "LeoQuad.pb.h"
#include "mcap/reader.hpp"

namespace gp = google::protobuf;

bool LoadSchema(const mcap::SchemaPtr schema, gp::SimpleDescriptorDatabase *protoDb)
{
    gp::FileDescriptorSet fdSet;
    if (!fdSet.ParseFromArray(static_cast<const void *>(schema->data.data()), schema->data.size()))
    {
        std::cerr << "failed to parse schema data" << std::endl;
        return false;
    }
    gp::FileDescriptorProto unused;
    for (int i = 0; i < fdSet.file_size(); ++i)
    {
        const auto &file = fdSet.file(i);
        if (!protoDb->FindFileByName(file.name(), &unused))
        {
            if (!protoDb->Add(file))
            {
                std::cerr << "failed to add definition " << file.name() << "to protoDB" << std::endl;
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input.mcap>" << std::endl;
        return 1;
    }
    const char *inputFilename = argv[1];

    mcap::McapReader reader;
    {
        const auto res = reader.open(inputFilename);
        if (!res.ok())
        {
            std::cerr << "Failed to open " << inputFilename << " for reading: " << res.message
                      << std::endl;
            return 1;
        }
    }
    auto messageView = reader.readMessages();

    ///////////////////////////////////////////////////////////////////////////
    // Example 1. Dynamically read fields
    //

    // Load schema definitions
    gp::SimpleDescriptorDatabase protoDb;
    gp::DescriptorPool protoPool(&protoDb);
    gp::DynamicMessageFactory protoFactory(&protoPool);

    for (auto itr = messageView.begin(); itr != messageView.end(); itr++)
    {
        const gp::Descriptor *descriptor = protoPool.FindMessageTypeByName(itr->schema->name);
        if (!descriptor)
        {
            // Load message's FileDescriptorSet into the DescriptorDatabase
            if (!LoadSchema(itr->schema, &protoDb))
            {
                reader.close();
                return 1;
            }
            descriptor = protoPool.FindMessageTypeByName(itr->schema->name);

            std::cout << "---------------------------------------------------------------" << std::endl;
            std::cout << "full name = " << descriptor->full_name() << std::endl;
            std::cout << "field count = " << descriptor->field_count() << std::endl;
            std::cout << descriptor->DebugString() << std::endl;
            for (auto fidx = 0; fidx < descriptor->field_count(); fidx++)
            {
                const gp::FieldDescriptor *fieldDescriptor = descriptor->field(fidx);
                std::cout << "\t" << fieldDescriptor->DebugString() << std::endl;
            }
        }

        // gp::Message *message = protoFactory.GetPrototype(descriptor)->New();
        // if (!message->ParseFromArray(static_cast<const void *>(itr->message.data),
        //                              itr->message.dataSize))
        // {
        //     std::cerr << "failed to parse message using included schema" << std::endl;
        //     reader.close();
        //     return 1;
        // }
        // std::cout << message->ShortDebugString() << std::endl;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Example 2. Read to statically generated class definition
    //
    for (auto itr = messageView.begin(); itr != messageView.end(); itr++)
    {
        if (itr->schema->encoding != "protobuf" || itr->schema->name != "dtproto.leoquad.LeoQuadStateTimeStamped")
        {
            continue;
        }

        dtproto::leoquad::LeoQuadStateTimeStamped message;
        if (!message.ParseFromArray(static_cast<const void *>(itr->message.data), itr->message.dataSize))
        {
            std::cerr << "could not parse dtproto.leoquad.LeoQuadStateTimeStamped" << std::endl;
            return 1;
        }
        std::cout << message.ShortDebugString() << std::endl;
    }

    // close the reader
    reader.close();

    return 0;
}