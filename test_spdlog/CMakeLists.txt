cmake_minimum_required(VERSION 3.16.3)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)

# find_package(spdlog REQUIRED CONFIG)
# target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog_header_only)
# target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

target_include_directories(${PROJECT_NAME} 
    PUBLIC "${CMAKE_SOURCE_DIR}/third_party/spdlog/include"
)
target_link_directories(${PROJECT_NAME} 
    PUBLIC ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
)
if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    message(STATUS "${PROJECT_NAME} is linked with spdlogd.")
    target_link_libraries(${PROJECT_NAME} PRIVATE spdlogd)
else()
    message(STATUS "${PROJECT_NAME} is linked with spdlog.")
    target_link_libraries(${PROJECT_NAME} PRIVATE spdlog)
endif()

# std::make_unique requires 'C++14'
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)