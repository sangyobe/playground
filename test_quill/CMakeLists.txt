cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

set(CMAKE_PREFIX_PATH /home/sean/.local/)
find_package(quill REQUIRED)

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE quill::quill
)
# quill requires 'C++14'
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)