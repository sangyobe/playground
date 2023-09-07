cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

# set(CMAKE_MODULE_PATH /home/sean/.local)

find_package(CapnProto REQUIRED CONFIG)
set(CMAKE_CXX_STANDARD 14)

file(GLOB SRCS "*.cpp" "*.c++")
add_executable(${PROJECT_NAME}
    ${SRCS}
)
target_link_libraries(${PROJECT_NAME} 
    CapnProto::capnp
    CapnProto::kj
#    capnp
#    kj
)