#pragma once

#include "utilities/materials.hpp"

class simple_shape {

public:

    simple_shape();

    void plane(struct material * bad_material);
    void eqTriangle(struct material* bad_material);
    void cube(struct material* bad_material);

    void cone(struct material* bad_material, int nFaces);
    void cylinder(struct material* bad_material, int nFaces);

    void sphere(struct material* bad_material, int nFaces);
    void torus(struct material* bad_material, int nFaces);
    void convexCone(struct material* bad_material, int nFaces);
};
