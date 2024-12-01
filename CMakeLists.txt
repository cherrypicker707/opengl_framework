cmake_minimum_required(VERSION 3.25)

project(opengl_framework)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
file(GLOB SOURCE_FILES source/*.c)
add_executable(test_program glad/src/glad.c ${SOURCE_FILES})
target_include_directories(test_program PUBLIC glad/include)
target_link_libraries(test_program PUBLIC GL glfw)
