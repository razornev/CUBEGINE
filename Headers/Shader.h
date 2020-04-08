#ifndef CUBEGINE_SHADER_H
#define CUBEGINE_SHADER_H
#include <string>
#include <vector>
#include <unordered_map>
#include "GLCall.h"

class Shader {
private:
    std::string shaderName;
    unsigned int rendererID;
    std::unordered_map<std::string, int> uniformLocationCache;

    std::vector<std::string> readShaders(const std::string& shaderName) const;

    static unsigned int compileShader(unsigned int type, std::string src);
    unsigned int createProgram(std::string& vertexSrc, std::string& fragmentSrc);
    int getUniformLocation(const std::string& name);
public:
    Shader(const std::string& shaderName);
    ~Shader();

    void bind() const;
    void unBind() const;
    void setUniform4f(const std::string& name, float uniform);
    void setUniform4f(const std::string& name, std::vector<float> uniform);
};


#endif //CUBEGINE_SHADER_H
