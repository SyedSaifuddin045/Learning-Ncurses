cmake_minimum_required(VERSION 3.0.0)

project(TEST_0)

add_executable(TEST_0 Test.cpp)

find_package(ncursescpp REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC ncursescpp::ncursescpp)
