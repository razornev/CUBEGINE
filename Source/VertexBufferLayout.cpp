#include "../Headers/VertexBufferLayout.h"
#include <iostream>
#include <sstream>

void VertexBufferLayout::pushFloat(unsigned int count){
    if(count > 4 || count < 1) throw std::out_of_range("Count must be either 1, 2, 3 or 4, as defined by OpenGL");

    elements.push_back({GL_FLOAT, count, GL_FALSE, sizeof(float)});
    stride += elements[elements.size()-1].getSize();
}
void VertexBufferLayout::pushUnsignedInt(unsigned int count){
    if(count > 4 || count < 1) throw std::out_of_range("Count must be either 1, 2, 3 or 4, as defined by OpenGL");

    elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE, sizeof(unsigned int)});
    stride += elements[elements.size()-1].getSize();
}
void VertexBufferLayout::pushChar(unsigned int count){
    if(count > 4 || count < 1) throw std::out_of_range("Count must be either 1, 2, 3 or 4, as defined by OpenGL");

    elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE, sizeof(char)});
    stride += elements[elements.size()-1].getSize();
}
