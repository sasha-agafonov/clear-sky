#include <GL/glu.h>
#include <cmath>
#include <iostream>
#include "Aero.h"
#include "Materials.h"
#include "Shape.h"

#define RED 0
#define SILVER 1
#define M200 2

Aero :: Aero(int speed) {
    tick = 0;
    this -> speed = speed;
    shape = new Shape();
}

void Aero :: changeAircraftSpeed(int speed) { this -> speed = speed; }

void Aero :: aeroplane(materialStruct* material, int aeroStyle, bool paused) {

    if (!paused && ++tick > 360) tick -= 360;

    glPushMatrix();

    body(material, aeroStyle);
    glTranslatef(6., 0., 0.35);

    if (aeroStyle == M200) wings(material, aeroStyle);
    else if (aeroStyle == SILVER) wings(material, aeroStyle);
    else wings(&aeroWhite, aeroStyle);

    glPushMatrix();
    glTranslatef(3.3, 0., -0.35);
    glRotatef(90., 0., 1., 0.);
    glRotatef((tick * (6 + speed * 2)) % 360, 0., 0., 1.);
    glScalef(0.3, 0.3, 0.3);
    propeller(material, aeroStyle);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    tail(material, aeroStyle);
    glPopMatrix();


}

void Aero :: body(materialStruct* material, int aeroStyle) {

    glPushMatrix();
    glRotatef(90., 0., 1., 0.);
    glScalef(0.9, 0.9, 1.);

    glPushMatrix();
    glScalef(1., 1., 1.2);
    glRotatef(180, 0., 1., 0.);
    shape -> hollowCylinder(material, 24, 16, 0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.,0., 2.4);
    glScalef(1., 1., 1.5);
    glTranslatef(0., 0., -1);
    gluCylinder(gluNewQuadric(), 1, 1.5, 2, 24, 16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 0., 5.8);
    glScalef(1.5, 1.5, 2.);
    glTranslatef(0., 0., -1);
    gluCylinder(gluNewQuadric(), 1, 1, 2, 24, 16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 0., 8.4);
    glScalef(1., 1., 0.6);
    glTranslatef(0., 0., -1);
    gluCylinder(gluNewQuadric(), 1.5, 1, 2, 24, 16);
    glPopMatrix();

    if (aeroStyle == RED || aeroStyle == SILVER) {
        glMaterialfv(GL_FRONT, GL_AMBIENT,    badPlastic.ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,    badPlastic.diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   badPlastic.specular);
        glMaterialf(GL_FRONT, GL_SHININESS,   badPlastic.shininess);
    } else {
        glMaterialfv(GL_FRONT, GL_AMBIENT,    material -> ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,    material -> diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   material -> specular);
        glMaterialf(GL_FRONT, GL_SHININESS,   material -> shininess);
    }

    glPushMatrix();
    glTranslatef(0., 0., 9.);
    glRotatef(180., 0., 0., 1.);
    gluDisk(gluNewQuadric(), 0., 1., 24., 4.);
    glPopMatrix();

    glPopMatrix();
}

void Aero :: wings(materialStruct* material, int aeroStyle) {

    // bottom wing
    glPushMatrix();
    glTranslatef(0., 0., -1.8);
    glScalef(1.2, 6.5, 0.1);
    shape -> cube(material);
    glPopMatrix();

    // top wing
    glPushMatrix();
    glTranslatef(0., 0., 1.8);
    glScalef(1.2, 7., 0.1);
    shape -> cube(material);
    glPopMatrix();

    // wing reinforcements
    glPushMatrix();
    glTranslatef(1., 5., 0.);
      glRotatef(-10, 1., 0., 0.);
      glScalef(0.07, 0.07, 1.8);
      if (aeroStyle == RED) shape -> cube(&aeroWhite);
      else shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1., -5., 0.);
      glRotatef(10, 1., 0., 0.);
      glScalef(0.07, 0.07, 1.8);
      if (aeroStyle == RED) shape -> cube(&aeroWhite);
      else shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1., -5., 0.);
      glRotatef(10, 1., 0., 0.);
      glScalef(0.07, 0.07, 1.8);
      if (aeroStyle == RED) shape -> cube(&aeroWhite);
      else shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1., 5., 0.);
      glRotatef(-10, 1., 0., 0.);
      glScalef(0.05, 0.05, 1.8);
      if (aeroStyle == RED) shape -> cube(&aeroWhite);
      else shape -> cube(material);
    glPopMatrix();

    // cabin reinforcements
    glPushMatrix();
    glTranslatef(-1., 1., 0.);
    glRotatef(-10, 1., 0., 0.);
    glScalef(0.07, 0.07, 0.75);
    glTranslatef(0., 0., 1.35);
    if (aeroStyle == RED) shape -> cube(&aeroWhite);
    else shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 1., 1., 0.);
    glRotatef(-10, 1., 0., 0.);
    glScalef(0.07, 0.07, 0.75);
    glTranslatef(0., 0., 1.35);
    if (aeroStyle == RED) shape -> cube(&aeroWhite);
    else shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 1., -1., 0.);
    glRotatef(10, 1., 0., 0.);
    glScalef(0.07, 0.07, 0.75);
    glTranslatef(0., 0., 1.35);
    if (aeroStyle == RED) shape -> cube(&aeroWhite);
    else shape -> cube(material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( -1., -1., 0.);
    glRotatef(10, 1., 0., 0.);
    glScalef(0.07, 0.07, 0.75);
    glTranslatef(0., 0., 1.35);
    if (aeroStyle == RED) shape -> cube(&aeroWhite);
    else shape -> cube(material);
    glPopMatrix();
}

void Aero :: tail(materialStruct* material, int aeroStyle) {

    // side wing
    glPushMatrix();
    glTranslatef(0., 2., 0.);
    glScalef(0.6, 1.2, 0.05);
    if (aeroStyle == RED) shape -> cube(&aeroWhite);
    else shape -> cube(material);
    glPopMatrix();

    // side wing
    glPushMatrix();
    glTranslatef(0., -2., 0.);
    glScalef(0.6, 1.2, 0.05);
    if (aeroStyle == RED) shape -> cube(&aeroWhite);
    else shape -> cube(material);
    glPopMatrix();

    // top wing
    glPushMatrix();
    glTranslatef(0.05, 0., 1.5);
    glRotatef(180., 0., 1.,0.);
    glScalef(0.6, 0.05, 0.65);
    if (aeroStyle == RED) shape -> triangularPrism(&aeroWhite);
    else shape -> triangularPrism(material);
    glTranslatef(1.5, 0.,0.);
    glScalef(0.5, 1., 1.);
    if (aeroStyle == RED) shape -> cube(&aeroWhite);
    else shape -> cube(material);
    glPopMatrix();

}

void Aero :: propeller(materialStruct* material, int aeroStyle) {

    if (aeroStyle == RED) {
        glMaterialfv(GL_FRONT, GL_AMBIENT,    redPlastic.ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,    redPlastic.diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   redPlastic.specular);
        glMaterialf(GL_FRONT, GL_SHININESS,   redPlastic.shininess);
    } else {
        glMaterialfv(GL_FRONT, GL_AMBIENT,    material -> ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,    material -> diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   material -> specular);
        glMaterialf(GL_FRONT, GL_SHININESS,   material -> shininess);
    }

    glPushMatrix();
    glTranslatef(0., 0., -1);
    gluCylinder(gluNewQuadric(), 1.5, 1, 2, 16, 12);
    glPopMatrix();

    // disk fill
    glPushMatrix();
    glTranslatef(0.,0.,1.);
    gluDisk(gluNewQuadric(), 0., 1., 16., 4.);
    glPopMatrix();

    // blade
    glPushMatrix();
    if (aeroStyle == RED) {
        glMaterialfv(GL_FRONT, GL_AMBIENT,    aeroWhite.ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,    aeroWhite.diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   aeroWhite.specular);
        glMaterialf(GL_FRONT, GL_SHININESS,   aeroWhite.shininess);
    }

    glTranslatef(3., 0., 0.);
    glRotatef(30., 1., 0., 0.);
    glScalef(3., 0.8, 0.15);
    gluSphere(gluNewQuadric(), 1, 12, 12);
    glPopMatrix();

    // blade
    glPushMatrix();
    glTranslatef(-3, 0., 0.);
    glRotatef(180, 0., 0., 1.);
    glRotatef(30., 1., 0., 0.);
    glScalef(3., 0.8, 0.15);
    gluSphere(gluNewQuadric(), 1, 12, 12);
    glPopMatrix();
}
