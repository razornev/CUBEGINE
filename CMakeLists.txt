cmake_minimum_required(VERSION 3.15)
project(CUBEGINE)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(dependencies/glfw)

add_executable(CUBEGINE main.cpp)
find_package(OpenGL REQUIRED)

target_link_libraries(CUBEGINE OpenGL::GL)
target_link_libraries(CUBEGINE glfw)
