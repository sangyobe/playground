cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)  # fsm2 requires C++_11