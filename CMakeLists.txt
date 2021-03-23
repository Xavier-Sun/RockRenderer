cmake_minimum_required(VERSION 3.1)

project(rock VERSION 0.1.0)

add_subdirectory(thirdparty)

add_executable(rock
    rock_main.cpp
    frame_buffer.cpp
    rasterizer.cpp)
target_link_libraries(rock PUBLIC glad)
target_link_libraries(rock PUBLIC glfw)
target_include_directories(rock PUBLIC ${PROJECT_SOURCE_DIR})