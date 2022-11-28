#ifndef FENCE_H
#define FENCE_H

#include "Materials.h"
#include "Shape.h"

class Fence {

public:
    Fence();
    void halfFence(materialStruct* material);
    void brokenFence(materialStruct* material);
    void pole(materialStruct* material);
    void drawFence(materialStruct* material);
    Shape* shape;
};

#endif // FENCE_H
