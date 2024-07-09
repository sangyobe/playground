cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

if("$ENV{ARTF_INSTALL_DIR}" STREQUAL "")
    message(STATUS "ARTF_INSTALL_DIR is not set. ${PROJECT_NAME} skipped.")
else()
    file(GLOB SRCS "*.cpp")
    add_executable(${PROJECT_NAME} ${SRCS})
    target_include_directories(${PROJECT_NAME} PRIVATE "$ENV{ARTF_INSTALL_DIR}/include")
endif()