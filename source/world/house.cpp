#ifdef _WIN32
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include "house.hpp"

house::house()
{
    shape_ = new shape();
}

void house::house_inner(struct material* bad_material)
{

    // base
    glPushMatrix();
    glTranslatef(0., -3, 0);
    glScalef(3, 6, 0.3);
    shape_->cube(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3., 0, 0);
    glScalef(0.5, 1, 0.3);
    shape_->cube(bad_material);
    glPopMatrix();

    // walls
    glPushMatrix();
    doorWall(bad_material);
    glRotatef(90., 0., 0., 1.);
    windowWall(bad_material);
    glRotatef(90., 0., 0., 1.);
    windowWall(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -6., 0);
    windowWall(bad_material);
    glRotatef(-90, 0., 0., 1);
    plainWall(bad_material);
    glRotatef(90, 0, 0, 1);
    windowWall(bad_material);
    glRotatef(180, 0, 0, 1);
    windowWall(bad_material);
    glPopMatrix();

    glPushMatrix();
    roofWall(bad_material, false);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., -6., 4.5);
    windowWall(bad_material);
    glRotatef(-90, 0., 0., 1);
    windowWall(bad_material);
    glRotatef(90, 0, 0, 1);
    windowWall(bad_material);
    glRotatef(180, 0, 0, 1);
    windowWall(bad_material);
    glRotatef(270, 0, 0, 1);
    plainWall(bad_material);
    glPopMatrix();

    // roof
    glPushMatrix();
    glTranslatef(0., -6., 4.5);
    roofWall(bad_material, true);
    glPopMatrix();



}

void house::roofWall(struct material* bad_material, bool doubleSided)
{

    glPushMatrix();
    glTranslatef(1.5, 0, 7.5);
    glRotatef(180, 0, 1, 0);
    glScalef(1.5, 3, 1.5);
    shape_->triangularPrism(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0, 7.5);
    glRotatef(180, 0, 1, 0);
    glRotatef(180, 0, 0, 1);
    glScalef(1.5, 3, 1.5);
    shape_->triangularPrism(bad_material);
    glPopMatrix();

    glPushMatrix();
    // roof with two sides sticking out or one
    // avoids clipping through nearby wall, e.g. if roof is on the first floor
    if (doubleSided) glScalef(1., 1.2, 1.);
    else {
        glTranslatef(0., 0.3, 0.);
        glScalef(1., 1.1, 1.); }

    glPushMatrix();
    glTranslatef(0., 0., 7);
    roof(bad_material);
    glRotatef(180, 0, 0, 1);
    roof(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 3.1, 9);
    glRotatef(90, 1, 0, 0);
    gluCylinder(gluNewQuadric(), 0.3, 0.3, 6.2, 12, 12);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 3.1, 9);
    glRotatef(90, 1, 0, 0);
    glRotatef(180, 0, 1, 0);
    gluDisk(gluNewQuadric(), 0, 0.3, 12, 12);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., -3.1, 9);
    glRotatef(90, 1, 0, 0);
    gluDisk(gluNewQuadric(), 0, 0.3, 12, 12);
    glPopMatrix();

    glPopMatrix();

}

void house ::plainWall(struct material* bad_material)
{
    glPushMatrix();
    glTranslatef(2.7, 0, 3);
    glScalef(0.3, 3, 3);
    shape_->cube(bad_material);
    glPopMatrix();

}

void house ::roof(struct material* bad_material)
{
    glPushMatrix();
    glTranslatef(2, 0, 0);
    glRotatef(45, 0, 1, 0);
    glScalef(3, 3, 0.15);
    shape_->cube(&houseRoof);
    glPopMatrix();
}


void house ::windowWall(struct material* bad_material)
{
    glPushMatrix();
    glTranslatef(2.7, 0, 0);

    glPushMatrix();
    glTranslatef(0, 0, 1);
    glScalef(0.3, 3, 1);
    shape_->cube(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3, 0, 3);
    glScalef(0.3, 1, 1);
    shape_->cube(&houseWindow);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 2, 3);
    glScalef(0.3, 1, 3);
    shape_->cube(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 5);
    glScalef(0.3, 3, 1);
    shape_->cube(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -2, 3);
    glScalef(0.3, 1, 3);
    shape_->cube(bad_material);
    glPopMatrix();
    glPopMatrix();

}

void house ::doorWall(struct material* bad_material)
{
    glPushMatrix();
    glTranslatef(2.7, 0, 0);

    // door
    glPushMatrix();
    glTranslatef(-0.3, 0, 2);
    glScalef(0.3, 1, 2);
    shape_->cube(&choco2);
    glPopMatrix();

    // handle
    glPushMatrix();
    glTranslatef(0.14, -0.5, 2);
    glScalef(0.15, 0.15, 0.15);
    gluSphere(gluNewQuadric(), 1, 12, 12);
    glPopMatrix();

    // walls
    glPushMatrix();
    glTranslatef(0, 2, 3);
    glScalef(0.3, 1, 3);
    shape_->cube(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 5);
    glScalef(0.3, 3, 1);
    shape_->cube(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -2, 3);
    glScalef(0.3, 1, 3);
    shape_->cube(bad_material);
    glPopMatrix();
    glPopMatrix();
}
