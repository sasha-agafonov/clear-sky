#pragma once

#include "utilities/materials.hpp"

class shape;

class fence {

public:
    fence();
    void halfFence(struct material* bad_material);
    void brokenFence(struct material* bad_material);
    void pole(struct material* bad_material);
    void drawFence(struct material* bad_material);
    shape* shape_ = nullptr;
};
