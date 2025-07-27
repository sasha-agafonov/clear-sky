#pragma once

class shape;

class aero
{
public:
    aero(int speed);
    void aeroplane(struct material * bad_material, int aeroStyle, bool paused);
    void body(struct material* bad_material, int aeroStyle);
    void wings(struct material* bad_material, int aeroStyle);
    void tail(struct material* bad_material, int aeroStyle);
    void propeller(struct material* bad_material, int aeroStyle);
    void changeAircraftSpeed(int speed);
    shape* shape_ = nullptr;
    int speed;

private:
    int tick;
};
