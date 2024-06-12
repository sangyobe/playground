cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

add_executable(${PROJECT_NAME}
    ${PROJECT_NAME}.cpp
)
# std::make_unique requires 'C++14'
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
