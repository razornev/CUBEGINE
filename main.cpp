#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

unsigned int compileShader(unsigned int type, std::string src){
    unsigned int shaderID = glCreateShader(type);
    const char* srcInChars = src.c_str();
    glShaderSource(shaderID, 1, &srcInChars, nullptr);
    glCompileShader(shaderID);

    int result;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    if(result ==GL_FALSE){
        int length;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(shaderID, length, &length, message);
        std::cout <<"Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(shaderID);
        return 0;
    }

    return shaderID;
};

static int createProgram(std::string& vertexSrc, std::string& fragmentSrc){
    unsigned int program = glCreateProgram();

    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexSrc);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentSrc);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    return program;
};

static std::string vertexSrc =
        "#version 460\n"
        "precision highp float;\n"
        "\n"
        "layout(location = 0) in vec4 position;\n"
        "void main()\n"
        "{\n"
        "gl_Position = position;\n"
        "}\n";

static std::string fragmentSrc =
        "#version 460\n"
        "precision highp float;\n"
        "\n"
        "out vec4 color;\n"
        "void main()\n"
        "{\n"
        "color = vec4(0.0, 0.0, 1.0, 1.0);\n"
        "}\n";

int main(void)
{
    GLFWwindow* window;


    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK){
        std::cout << "An error has happened." <<std::endl;
    } else {
        std::cout <<"No error." << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    unsigned int program = createProgram(vertexSrc, fragmentSrc);
    glUseProgram(program);

    float positions[] = {
            -0.5f, -0.5f,
             0.0f,   0.5f,
             0.5f,  -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}