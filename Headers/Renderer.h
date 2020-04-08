#ifndef CUBEGINE_RENDERER_H
#define CUBEGINE_RENDERER_H

#include "GLCall.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"

class Renderer{
public:
    void clear() const;
    void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;


};

#endif //CUBEGINE_RENDERER_H
