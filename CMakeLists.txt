cmake_minimum_required(VERSION 3.12)
project(CppPlaygroud)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(DebugUtil)
include(GetDirectoryName)


# DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update...")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules.")
        endif()
    endif()
endif()
# CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/third_party/spdlog/CMakeLists.txt")
    message(FATAL_ERROR "The spdlog submodules was not downloaded. GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/third_party/yaml-cpp/CMakeLists.txt")
    message(FATAL_ERROR "The yaml-cpp submodules was not downloaded. GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/third_party/glog/CMakeLists.txt")
    message(FATAL_ERROR "The glog submodules was not downloaded. GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# set(gRPC_INSTALL ON)
# set(gRPC_BUILD_TESTS OFF)
# add_subdirectory(third_party/grpc)

# set(SPDLOG_INSTALL ON)
add_subdirectory(third_party/spdlog)

# set(YAML_CPP_INSTALL ON)
add_subdirectory(third_party/yaml-cpp)

set(BUILD_TESTING OFF) # disable testing for glog and capnproto
add_subdirectory(third_party/glog)

# add_subdirectory(third_party/capnproto)

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/include")

file(GLOB TEST_DIRS "test_*")
foreach(test_dir ${TEST_DIRS})
    add_subdirectory(${test_dir})
endforeach()

# enable_testing()
# add_subdirectory(tests)
