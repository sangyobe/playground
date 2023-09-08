cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

set(CMAKE_MODULE_PATH /home/sean/.local)
set(CMAKE_CXX_STANDARD 14)

find_package(CapnProto REQUIRED CONFIG)
capnp_generate_cpp(CAPNP_SRCS CPANP_HDRS proto/myproto.capnp)
message(STATUS "CAPNP_SRCS: ${CAPNP_SRCS}")
message(STATUS "CPANP_HDRS: ${CPANP_HDRS}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")


file(GLOB SRCS "*.cpp" "*.c++")
add_executable(${PROJECT_NAME}
    ${SRCS} ${CAPNP_SRCS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    CapnProto::capnp
    CapnProto::kj
)
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_BINARY_DIR}
)