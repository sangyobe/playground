cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

find_package(spdlog REQUIRED)

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)
#target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog_header_only)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
# std::make_unique requires 'C++14'
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)