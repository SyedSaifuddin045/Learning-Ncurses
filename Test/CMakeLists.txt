cmake_minimum_required(VERSION 3.0.0)

project(TEST_0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(TEST_0 Test.cpp)

find_package(ncursescpp REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC ncursescpp::ncursescpp)
