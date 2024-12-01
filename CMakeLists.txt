cmake_minimum_required(VERSION 3.25)

project(opengl_framework)
set(CMAKE_EXPORT_COMMANDS 1)
file(GLOB SOURCE_FILES source/*.c)
add_executable(test_program ${SOURCE_FILES})
