cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)
# std::make_unique requires 'C++14'
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)