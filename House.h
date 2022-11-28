#ifndef HOUSE_H
#define HOUSE_H

#include "Materials.h"
#include "Shape.h"

class House {

public:
    House();
    void house(materialStruct* material);
    void windowWall(materialStruct* material);
    void plainWall(materialStruct* material);
    void roofWall(materialStruct* material, bool doubleSided);
    void roof(materialStruct* material);
    void doorWall(materialStruct* material);
    Shape* shape;
};

#endif // HOUSE_H
