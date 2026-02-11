cmake_minimum_required(VERSION 3.10.1)
project(renderer)

message(${CMAKE_CURRENT_SOURCE_DIR})
add_library(window src/window.cpp)
target_include_directories(window PUBLIC ../engine/raytracer/include/)