#include "House.h"
#include <GL/glu.h>


House :: House() {
    shape = new Shape();
}

void House :: house(materialStruct* material) {

    // base
    glPushMatrix();
    glTranslatef(0., -3, 0);
    glScalef(3, 6, 0.3);
    shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3., 0, 0);
    glScalef(0.5, 1, 0.3);
    shape -> cube(material);
    glPopMatrix();

    // walls
    glPushMatrix();
    doorWall(material);
    glRotatef(90., 0., 0., 1.);
    windowWall(material);
    glRotatef(90., 0., 0., 1.);
    windowWall(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -6., 0);
    windowWall(material);
    glRotatef(-90, 0., 0., 1);
    plainWall(material);
    glRotatef(90, 0, 0, 1);
    windowWall(material);
    glRotatef(180, 0, 0, 1);
    windowWall(material);
    glPopMatrix();

    glPushMatrix();
    roofWall(material, false);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., -6., 4.5);
    windowWall(material);
    glRotatef(-90, 0., 0., 1);
    windowWall(material);
    glRotatef(90, 0, 0, 1);
    windowWall(material);
    glRotatef(180, 0, 0, 1);
    windowWall(material);
    glRotatef(270, 0, 0, 1);
    plainWall(material);
    glPopMatrix();

    // roof
    glPushMatrix();
    glTranslatef(0., -6., 4.5);
    roofWall(material, true);
    glPopMatrix();



}

void House :: roofWall(materialStruct* material, bool doubleSided) {

    glPushMatrix();
    glTranslatef(1.5, 0, 7.5);
    glRotatef(180, 0, 1, 0);
    glScalef(1.5, 3, 1.5);
    shape -> triangularPrism(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0, 7.5);
    glRotatef(180, 0, 1, 0);
    glRotatef(180, 0, 0, 1);
    glScalef(1.5, 3, 1.5);
    shape -> triangularPrism(material);
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
    roof(material);
    glRotatef(180, 0, 0, 1);
    roof(material);
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

void House :: plainWall(materialStruct* material) {
    glPushMatrix();
    glTranslatef(2.7, 0, 3);
    glScalef(0.3, 3, 3);
    shape -> cube(material);
    glPopMatrix();

}

void House :: roof(materialStruct* material) {
    glPushMatrix();
    glTranslatef(2, 0, 0);
    glRotatef(45, 0, 1, 0);
    glScalef(3, 3, 0.15);
    shape -> cube(&houseRoof);
    glPopMatrix();
}


void House :: windowWall(materialStruct* material) {

    // wall with window
    glPushMatrix();
    glTranslatef(2.7, 0, 0);

    glPushMatrix();
    glTranslatef(0, 0, 1);
    glScalef(0.3, 3, 1);
    shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3, 0, 3);
    glScalef(0.3, 1, 1);
    shape -> cube(&houseWindow);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 2, 3);
    glScalef(0.3, 1, 3);
    shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 5);
    glScalef(0.3, 3, 1);
    shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -2, 3);
    glScalef(0.3, 1, 3);
    shape -> cube(material);
    glPopMatrix();
    glPopMatrix();

}

void House :: doorWall(materialStruct* material) {
    glPushMatrix();
    glTranslatef(2.7, 0, 0);

    // door
    glPushMatrix();
    glTranslatef(-0.3, 0, 2);
    glScalef(0.3, 1, 2);
    shape -> cube(&choco2);
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
    shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 5);
    glScalef(0.3, 3, 1);
    shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -2, 3);
    glScalef(0.3, 1, 3);
    shape -> cube(material);
    glPopMatrix();
    glPopMatrix();
}
