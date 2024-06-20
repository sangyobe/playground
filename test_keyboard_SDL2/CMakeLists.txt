# cmake_minimum_required(VERSION 3.12)

# GetCurrentDirectoryName(PrjName)

# project(${PrjName})

# find_package(SDL2 REQUIRED)
# if (SDL2_FOUND)
#     message(STATUS "SDL2 found ${SDL2_LIBRARIES}")
# else()
#     message(STATUS "SDL2 not found")
# endif()

# if (NOT APPLE)
#     file(GLOB SRCS "*.cpp")
#     add_executable(${PROJECT_NAME}
#         ${SRCS}
#     )
#     target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
#     # glog requires 'C++14'
#     set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
# endif()