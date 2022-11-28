#ifndef SHAPE_H
#define SHAPE_H

#include "Materials.h"

class Shape {

public:

    Shape();

    // returns length of a vector
    double vectorLength(double, double, double);

    void icosahedron(materialStruct* material);

    void cube(materialStruct* material);

    void triangularPrism(materialStruct* material);

    void hollowCylinder(materialStruct* material, int segments, int rings, double innerRad);

};

#endif // SHAPE_H
