cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

# SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -rdynamic")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -rdynamic")

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
