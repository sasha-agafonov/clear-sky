#ifndef PINE_H
#define PINE_H

#include "Materials.h"
#include "Shape.h"

class Pine {

public:
    Pine();
    void pine();
    void stump();
    void drawPines();

    Shape* shape;
};

#endif // PINE_H
