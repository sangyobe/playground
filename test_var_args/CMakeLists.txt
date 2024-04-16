cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

file(GLOB SRCS "test_var_args_*.cpp")
foreach(src ${SRCS})
    get_filename_component(TargetName ${src} NAME_WE)
    add_executable(${TargetName} ${src})
    target_link_libraries(${TargetName} pthread)
    set_property(TARGET ${TargetName} PROPERTY CXX_STANDARD 17)
endforeach()