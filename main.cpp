#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <fstream>
#include "Headers/Renderer.h"
#include <stdexcept>

int main(int argc, char * argv[]){
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    unsigned int width = 680;
    unsigned int height = 680;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if(glewInit() != GLEW_OK){
        std::cout << "An error has happened." << std::endl;
    } else {
        std::cout <<"No error." << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    {
        float positions[] = {
                -0.5f, -0.5f,
                0.5f, -0.5f,
                0.5f, 0.5f,
                -0.5f, 0.5F
        };

        unsigned int indices[] = {
                0, 1, 2,
                2, 3, 0
        };

        Shader shader("cubeShader");
        VertexArray va;
        VertexBuffer vb(positions, 4 * 2 * sizeof(float));
        VertexBufferLayout layout;

        layout.pushFloat(2);
        va.AddBuffer(vb, layout);

        IndexBuffer ib(indices, 6);
        shader.setUniform4f("u_Color", {0.2f, 0.3f, 0.4f, 1.0f});

        vb.unBind();
        ib.unBind();
        va.unBind();
        shader.unBind();

        Renderer renderer;

        float r = 0.0f;
        float increment = 0.05f;
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window)) {
            /* Render here */
            renderer.clear();

            shader.bind();
            shader.setUniform4f("u_Color", {r, 0.3f, 0.4f, 1.0f});

            va.bind();
            ib.bind();
            renderer.draw(va, ib, shader);

            if (r > 1.0f) {
                increment = -0.05f;
            }
            if (r < 0.0f) {
                increment = 0.05f;
            }
            r += increment;

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}
#pragma clang diagnostic pop