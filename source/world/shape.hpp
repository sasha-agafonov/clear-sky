#pragma once

#include "utilities/materials.hpp"

class shape {

public:

    shape();

    double vectorLength(double, double, double);

    void icosahedron(struct material * bad_material);

    void cube(struct material* bad_material);

    void triangularPrism(struct material* bad_material);

    void hollowCylinder(struct material* bad_material, int segments, int rings, double innerRad);
};
