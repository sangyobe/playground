cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

find_package(Protobuf CONFIG REQUIRED)

file(GLOB_RECURSE PROTO_SRCS "foxglove/*.cpp" "foxglove/*.cc" "LeoQuad*.cc")

set(TARGETS test_mcap_writer test_mcap_reader)

foreach(TARGET ${TARGETS})
    add_executable(${TARGET}
        ${TARGET}.cpp
        BuildFileDescriptorSet.cpp
        ${PROTO_SRCS}
    )
    target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(${TARGET} PRIVATE dtproto protobuf::libprotobuf)
    # std::make_unique requires 'C++17'
    set_property(TARGET ${TARGET} PROPERTY CXX_STANDARD 17)
endforeach()
