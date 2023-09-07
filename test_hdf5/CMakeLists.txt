cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)

target_include_directories(${PROJECT_NAME} PRIVATE /usr/include/hdf5/serial)
target_link_directories(${PROJECT_NAME} PRIVATE /usr/lib/x86_64-linux-gnu/hdf5/serial)
target_link_libraries(${PROJECT_NAME} hdf5)