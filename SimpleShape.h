#ifndef SIMPLESHAPE_H
#define SIMPLESHAPE_H

#include <GL/glu.h>
#include "Materials.h"

class SimpleShape {

public:

    SimpleShape();

    void plane(materialStruct* material);
    void eqTriangle(materialStruct* material);
    void cube(materialStruct* material);

    void cone(materialStruct* material, int nFaces); // cone with 3 faces is a pyramid
    void cylinder(materialStruct* material, int nFaces); // cylinder with 3 faces is a prism

    void sphere(materialStruct* material, int nFaces);
    void torus(materialStruct* material, int nFaces);
    void convexCone(materialStruct* material, int nFaces);
};

#endif // SIMPLESHAPE_H
