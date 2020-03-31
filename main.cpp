#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <fstream>

#define ASSERT(x) if (!(x)) __builtin_trap();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))


static void GLClearError(){
    while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line){
    while(GLenum error = glGetError()){
        std::cout << "[OpenGL Error] {" << error << "}: "
        << function << " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}


unsigned int compileShader(unsigned int type, std::string src){
    unsigned int shaderID = glCreateShader(type);
    const char* srcInChars = src.c_str();
    GLCall(glShaderSource(shaderID, 1, &srcInChars, nullptr));
    GLCall(glCompileShader(shaderID));

    //this segment of code should be refactored into another function
    //also, this harms the principle of OCP
    int result;
    GLCall(glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result));
    if(result ==GL_FALSE){int length;
        GLCall(glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length));
        char* message = (char*)alloca(length * sizeof(char));
        GLCall(glGetShaderInfoLog(shaderID, length, &length, message));
        std::cout <<"Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << message << std::endl;
        GLCall(glDeleteShader(shaderID));
        return 0;
    }

    return shaderID;
};

static int createProgram(std::string& vertexSrc, std::string& fragmentSrc){
    unsigned int program = glCreateProgram();

    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexSrc);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentSrc);

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));

    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    return program;
};

//function does not obey the principle of OCP -- should be refactored later
//function also implements multiple levels of abstraction
static std::vector<std::string> readShaders(std::string& shaderName){
    std::string vertexPath = "res/shaders/"+shaderName+"/"+shaderName+".vert";
    std::string fragmentPath = "res/shaders/"+shaderName+"/"+shaderName+".frag";

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

    unsigned int width = 680;
    unsigned int height = 680;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(680, 680, "Hello World", NULL, NULL);


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK){
        std::cout << "An error has happened." <<std::endl;
    } else {
        std::cout <<"No error." << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    unsigned int program = createProgram(shaders[0], shaders[1]);
    GLCall(glUseProgram(program));

    float positions[] = {
            -0.5f, -0.5f,
             0.5f, -0.5f,
             0.5f,  0.5f,
            -0.5f,  0.5F
    };

    unsigned int indices[] ={
        0, 1, 2,
        2, 3, 0
    };

    unsigned int buffer;
    GLCall(glGenBuffers(1, &buffer));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
    GLCall(glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), positions, GL_STATIC_DRAW));

    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

    unsigned int ibo;
    GLCall(glGenBuffers(1, &ibo));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //glDrawArrays(GL_TRIANGLES, 0, 6);
        //because of index buffer

        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}