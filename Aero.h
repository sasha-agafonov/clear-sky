#ifndef AERO_H
#define AERO_H

#include "WorldWidget.h"
#include "Shape.h"

class Shape;

class Aero {

public:
    Aero(int speed);
    void aeroplane(materialStruct* material, int aeroStyle, bool paused);
    void body(materialStruct* material, int aeroStyle);
    void wings(materialStruct* material, int aeroStyle);
    void tail(materialStruct* material, int aeroStyle);
    void propeller(materialStruct* material, int aeroStyle);
    void changeAircraftSpeed(int speed);
    Shape* shape;
    int speed;

private:
    int tick;

};

#endif // AERO_H
