cmake_minimum_required(VERSION 3.10.1)
project(tinyraytracer)

add_subdirectory(gui)

add_executable(main WIN32 main.cpp)
target_link_libraries(main PRIVATE window)