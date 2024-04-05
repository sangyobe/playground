cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -mfma")

GetCurrentDirectoryName(PrjName)

project(${PrjName})

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)