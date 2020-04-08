#ifndef CUBEGINE_VERTEXBUFFERLAYOUT_H
#define CUBEGINE_VERTEXBUFFERLAYOUT_H
#include "GLCall.h"
#include <vector>
#include <stdexcept>


struct VertexBufferElement{
    unsigned int GLtype;
    unsigned int count;
    unsigned char normalized;
    unsigned int sizeOfType;

    unsigned int getSize() const {
        return count * sizeOfType;
    }
};


class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> elements;
    unsigned int stride;
public:

    inline VertexBufferLayout() { stride = 0; }

    void pushFloat(unsigned int count);
    void pushUnsignedInt(unsigned int count);
    void pushChar(unsigned int count);

    inline std::vector<VertexBufferElement> getElements() const { return elements; }
    inline unsigned int getStride() const { return stride; }
};


#endif //CUBEGINE_VERTEXBUFFERLAYOUT_H
