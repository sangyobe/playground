cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17) # [[nodiscard]]C++17, [[noreturn]]C++11