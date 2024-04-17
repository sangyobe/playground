cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

find_package(Protobuf CONFIG REQUIRED)

file(GLOB_RECURSE SRCS "*.cpp" "*.cc")
add_executable(${PROJECT_NAME}
    ${SRCS}
)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE dtproto protobuf::libprotobuf)
# std::make_unique requires 'C++17'
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)