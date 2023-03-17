cmake_minimum_required(VERSION 3.0.0)

project(MOUSE_0)

add_executable(MOUSE_0 Mouse.cpp)

find_package(ncursescpp REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC ncursescpp::ncursescpp)
