cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

# constexpr is introduced in C++11 but fully supported since C++14
set(CMAKE_CXX_STANDARD 14)

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)