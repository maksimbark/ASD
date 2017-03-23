cmake_minimum_required(VERSION 3.6)
project(check)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(check ${SOURCE_FILES})