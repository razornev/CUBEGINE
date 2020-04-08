#ifndef CUBEGINE_VERTEXBUFFER_H
#define CUBEGINE_VERTEXBUFFER_H
#include "GLCall.h"

class VertexBuffer{
private:
    unsigned int rendererID;
public:
    VertexBuffer(const void* data, unsigned int size);
    virtual ~VertexBuffer();

    void bind() const;
    void unBind() const;
};

#endif //CUBEGINE_VERTEXBUFFER_H
