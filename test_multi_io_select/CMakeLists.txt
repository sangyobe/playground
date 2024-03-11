cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

add_executable(test_fread
    test_fread.cpp
)

add_executable(test_fwrite
    test_fwrite.cpp
)
