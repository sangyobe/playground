cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

find_package (glog 0.6.0 REQUIRED)

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)
target_link_libraries(${PROJECT_NAME} glog::glog)
# glog requires 'C++14'
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)