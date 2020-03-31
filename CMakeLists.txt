cmake_minimum_required(VERSION 3.15)
project(CUBEGINE)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL)

file(REMOVE ${CMAKE_CURRENT_BINARY_DIR}/res)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_definitions(-DGLEW_STATIC)

add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/glew/build/cmake)

add_executable(CUBEGINE main.cpp Source/Texture.cpp Headers/Texture.h Headers/stb_image.h Source/stb_image.cpp)

target_include_directories(CUBEGINE PRIVATE
        dependencies/GLEW/include
        )
target_link_libraries(CUBEGINE glfw glew_s OpenGL::GL)
