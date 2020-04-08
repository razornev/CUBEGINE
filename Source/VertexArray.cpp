#include "../Headers/VertexArray.h"

VertexArray::VertexArray() {
    GLCall(glGenVertexArrays(1, &rendererID));
    bind();
}

VertexArray::~VertexArray() {
    unBind();
    GLCall(glDeleteVertexArrays(1, &rendererID));
}

void VertexArray::bind() const { GLCall(glBindVertexArray(rendererID)); }

void VertexArray::unBind() const { GLCall(glBindVertexArray(0)); }

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
    bind();
    vb.bind();
    unsigned int offset = 0;
    const auto& elements = layout.getElements();
    for(unsigned int i = 0; i < elements.size(); i++){
        const auto& element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count, element.GLtype, element.normalized, layout.getStride(), (const void*)offset));
        offset += element.getSize();
    }
}
