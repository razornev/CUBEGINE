#ifndef CUBEGINE_VERTEXARRAY_H
#define CUBEGINE_VERTEXARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "GLCall.h"

class VertexArray {
private:
    unsigned int rendererID;
public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void bind() const;
    void unBind() const;
};


#endif //CUBEGINE_VERTEXARRAY_H
