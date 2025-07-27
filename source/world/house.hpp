#pragma once

#include "utilities/materials.hpp"
#include "world/shape.hpp"

class house
{
public:

    house();
    void house_inner(struct material* bad_material);
    void windowWall(struct material* bad_material);
    void plainWall(struct material* bad_material);
    void roofWall(struct material* bad_material, bool doubleSided);
    void roof(struct material* bad_material);
    void doorWall(struct material* bad_material);

    shape* shape_;
};
