#ifndef CUBEGINE_INDEXBUFFER_H
#define CUBEGINE_INDEXBUFFER_H

#include "GLCall.h"

class IndexBuffer {
private:
    unsigned int rendererID;
    unsigned int count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    virtual ~IndexBuffer();

    void bind() const;
    void unBind() const;

    inline unsigned int getCount() const { return count; } //temptation to break LOD, should be removed
};


#endif //CUBEGINE_INDEXBUFFER_H
