cmake_minimum_required(VERSION 3.25)

project(opengl_framework)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
file(GLOB SOURCE_FILES source/*.c glad/source/*.c)

add_library(opengl_framework ${SOURCE_FILES})
target_include_directories(opengl_framework PUBLIC include glad/include)
target_link_libraries(opengl_framework PUBLIC m GL glfw)

add_executable(example source/example/main.c)
target_include_directories(example PUBLIC include)
target_link_libraries(example PUBLIC opengl_framework)
