# cmake_minimum_required(VERSION 3.4...3.18)
# project(test_pybind11)

# add_library(test_pybind11 STATIC test_pybind11.cpp)
# set_target_properties(test_pybind11 PROPERTIES POSITION_INDEPENDENT_CODE ON)

# # could deplay test_pybind11 as  C++ library
# # create executable for unit testing
# # create separate executable

# execute_process(COMMAND python-config --cflags OUTPUT_VARIABLE PYTHON_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
# execute_process(COMMAND pybind11-config --include OUTPUT_VARIABLE PYBIND11_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
# execute_process(COMMAND python-config --ldflags OUTPUT_VARIABLE PYTHON_LDFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
# message(STATUS "PYTHON_CFLAGS : ${PYTHON_CFLAGS}")
# message(STATUS "PYTHON_LDFLAGS : ${PYTHON_LDFLAGS}")


# add_subdirectory(pybind11)
# pybind11_add_module(test_pybind11_module test_pybind11_module.cpp)
# # add_library(test_pybind11_module SHARED test_pybind11_module.cpp)
# # target_include_directories(test_pybind11_module PRIVATE /home/sean/.pyenv/versions/3.12.0/include/python3.12)

# # target_link_libraries(test_pybind11_module PRIVATE pybind11::module)
# target_link_libraries(test_pybind11_module PRIVATE test_pybind11)

# # target_compile_options(test_pybind11_module PRIVATE ${PYTHON_CFLAGS})
# # target_link_options(test_pybind11_module PRIVATE ${PYTHON_LDFLAGS})
# # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PYTHON_CFLAGS} ${PYBIND11_CFLAGS}")
# # set_target_properties(test_pybind11_module PROPERTIES LINK_FLAGS "${PYTHON_LDFLAGS}")
