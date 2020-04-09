#include <c++/4.8.3/fstream>
#include "../Headers/Shader.h"
#include <iostream>

unsigned int Shader::compileShader(unsigned int type, std::string src){
    unsigned int shaderID = glCreateShader(type);
    const char* srcInChars = src.c_str();
    GLCall(glShaderSource(shaderID, 1, &srcInChars, nullptr));
    GLCall(glCompileShader(shaderID));

    //this segment of code should be refactored into another function
    //also, this harms the principle of OCP
    int result;
    GLCall(glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result));
    if(result ==GL_FALSE){
        int length;
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

unsigned int Shader::createProgram(std::string& vertexSrc, std::string& fragmentSrc){
    unsigned int program = glCreateProgram();

    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexSrc);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentSrc);

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));

    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    return program;
};

//function does not obey the principle of OCP, because more shaders could be added -- should be refactored later
//function also implements multiple levels of abstraction
std::vector<std::string> Shader::readShaders(const std::string& shaderName) const {
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


Shader::Shader(const std::string &shaderName): shaderName(shaderName), rendererID(0) {
    std::vector<std::string> shaders = readShaders(shaderName);
    rendererID = createProgram(shaders[0], shaders[1]);
    bind();
}

Shader::~Shader() {
    unBind();
    GLCall(glDeleteProgram(rendererID));
}

void Shader::bind() const {
    GLCall(glUseProgram(rendererID));
}

void Shader::unBind() const {
    GLCall(glUseProgram(0));
}

int Shader::getUniformLocation(const std::string &name) {
    if(uniformLocationCache.find(name) != uniformLocationCache.end()){
        return uniformLocationCache[name];
    }

    int location = 0;
    GLCall(location = glGetUniformLocation(rendererID, "u_Color"));
    if(location < 0) {
        std::cout << "Warning: uniform '" << name << "' does't exist!" << std::endl;
    }
    uniformLocationCache[name] = location;
    return location;
}

void Shader::setUniform4f(const std::string &name, float uniform) {
    int location = getUniformLocation(name);
    GLCall(glUniform1f(location, uniform));
}

void Shader::setUniform4f(const std::string &name, std::vector<float> uniform) {
    int location = getUniformLocation(name);
    GLCall(glUniform4f(location, uniform[0], uniform[1], uniform[2], uniform[3]));
}
