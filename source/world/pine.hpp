#pragma once

#include "utilities/materials.hpp"
#include "world/shape.hpp"

class pine {

public:
    pine();
    void pine_inner();
    void stump();
    void drawPines();

    shape* shape_;
};
