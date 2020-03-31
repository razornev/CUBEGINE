#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

unsigned int compileShader(unsigned int type, std::string src){
    unsigned int shaderID = glCreateShader(type);
    const char* srcInChars = src.c_str();
    glShaderSource(shaderID, 1, &srcInChars, nullptr);
    glCompileShader(shaderID);

    //this segment of code should be refactored into another function
    //also, this harms the principle of OCP
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

std::string readFile(std::string path){
    std::ifstream stream(path);
    std::stringbuf buffer;
}

//function does not obey the principle of OCP -- should be refactored later
//function also implements multiple levels of abstraction
static std::vector<std::string> readShaders(std::string& shaderName){
    std::string vertexPath = "shaders/"+shaderName+"/"+shaderName+".vert";
    std::string fragmentPath = "shaders/"+shaderName+"/"+shaderName+".frag";

    std::ifstream vertexStream(vertexPath);
    std::ifstream fragmentStream(fragmentPath);

    std::vector<std::string> shaders;
    shaders.reserve(2);

    shaders.emplace_back( std::string{(std::istreambuf_iterator<char>(vertexStream)), std::istreambuf_iterator<char>()} );
    shaders.emplace_back( std::string{(std::istreambuf_iterator<char>(fragmentStream)), std::istreambuf_iterator<char>()} );
    return shaders;
}

int main(int argc, char * argv[])
{
    GLFWwindow* window;
    std::string shaderName = "cubeShader";
    std::vector<std::string> shaders = readShaders(shaderName);

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

    unsigned int program = createProgram(shaders[0], shaders[1]);
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