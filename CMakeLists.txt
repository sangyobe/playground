cmake_minimum_required(VERSION 3.12)
project(CppPlaygroud)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(DebugUtil)
include(GetDirectoryName)

file(GLOB TEST_DIRS "test_*")
foreach(test_dir ${TEST_DIRS})
    add_subdirectory(${test_dir})
endforeach()

# enable_testing()
# add_subdirectory(tests)