cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

find_package(absl REQUIRED CONFIG)

# Abseil requires C++14
set(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS "*.cpp")
add_executable(${PROJECT_NAME}
    ${SRCS}
)
# Declare dependency on the absl::strings library
target_link_libraries(${PROJECT_NAME} 
    absl::flags
    absl::flags_parse
    absl::strings
)
