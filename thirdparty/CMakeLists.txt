cmake_minimum_required(VERSION 3.1)

add_subdirectory(glfw)

add_library(glad STATIC glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)