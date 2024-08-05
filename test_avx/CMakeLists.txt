cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -mfma")

GetCurrentDirectoryName(PrjName)

project(${PrjName})

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME} ${SRCS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

if("$ENV{ARTF_INSTALL_DIR}" STREQUAL "")
    message(STATUS "ARTF_INSTALL_DIR is not set. ${PROJECT_NAME} skipped performance checking.")
else()
    target_compile_definitions(${PROJECT_NAME} PUBLIC AVX_PERFORMANCE)
    target_include_directories(${PROJECT_NAME} PRIVATE "$ENV{ARTF_INSTALL_DIR}/include")
    target_link_directories(${PROJECT_NAME} PRIVATE "$ENV{ARTF_INSTALL_DIR}/lib")
    target_link_libraries(${PROJECT_NAME} PRIVATE dtcore)
endif()