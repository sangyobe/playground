cmake_minimum_required(VERSION 3.12)

GetCurrentDirectoryName(PrjName)

project(${PrjName})

if (NOT APPLE)
    file(GLOB SRCS "*.cpp")
    add_executable(${PROJECT_NAME}
        ${SRCS}
    )
    # target_link_libraries(${PROJECT_NAME} )
    # glog requires 'C++14'
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
endif()