#ifndef CUBEGINE_GLCALL_H
#define CUBEGINE_GLCALL_H

#include <GL/glew.h>

#define ASSERT(x) if (!(x)) __builtin_trap(); //__debugbreak() for Visual Studio
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);


#endif //CUBEGINE_GLCALL_H
