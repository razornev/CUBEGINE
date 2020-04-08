cmake_minimum_required(VERSION 3.15)
project(CUBEGINE)

set(CMAKE_CXX_STANDARD 20)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/shaders/cubeShader/cubeShader.vert
        ${CMAKE_CURRENT_BINARY_DIR}/res/shaders/cubeShader/cubeShader.vert)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/shaders/cubeShader/cubeShader.frag
        ${CMAKE_CURRENT_BINARY_DIR}/res/shaders/cubeShader/cubeShader.frag)

add_definitions(-DGLEW_STATIC)

add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/glew/build/cmake)

find_package(OpenGL)

add_executable(CUBEGINE main.cpp Source/Texture.cpp Headers/Texture.h Headers/stb_image.h Source/stb_image.cpp Headers/Renderer.h Source/Renderer.cpp Headers/VertexBuffer.h Source/VertexBuffer.cpp Source/IndexBuffer.cpp Headers/IndexBuffer.h Headers/VertexArray.h Source/VertexBufferLayout.cpp Headers/VertexBufferLayout.h Source/VertexArray.cpp Source/Shader.cpp Headers/Shader.h Headers/GLCall.h)

target_include_directories(CUBEGINE PRIVATE
        dependencies/GLEW/include
        )
target_link_libraries(CUBEGINE glfw glew_s OpenGL::GL)


