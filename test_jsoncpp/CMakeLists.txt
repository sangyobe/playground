# cmake_minimum_required(VERSION 3.12)

# GetCurrentDirectoryName(PrjName)

# project(${PrjName})

# find_package(jsoncpp REQUIRED CONFIG)

# file(GLOB SRCS "*.cpp")
# add_executable(${PROJECT_NAME}
#     ${SRCS}
# )
# target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)
# # std::make_unique requires 'C++17'
# set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)