cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

add_executable(${PROJECT_NAME}
    ${PROJECT_NAME}.cpp
)
# std::make_unique requires 'C++14'
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)


add_executable(test_smartptr_simplecache
    test_smartptr_simplecache.cpp
)
set_property(TARGET test_smartptr_simplecache PROPERTY CXX_STANDARD 14)