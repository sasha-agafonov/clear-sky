#include "Pine.h"
#include <GL/glu.h>

Pine::Pine() {
    shape = new Shape();
}

void Pine :: pine() {

    glMaterialfv(GL_FRONT, GL_AMBIENT,    choco.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    choco.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   choco.specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   choco.shininess);

    glPushMatrix();
    glScalef(0.8, 0.8, 5);
    gluCylinder(gluNewQuadric(), 1, 1, 1, 12, 1);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT,    piny.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    piny.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   piny.specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   piny.shininess);

    glPushMatrix();
    glTranslatef(0., 0., 3);
    glScalef(3, 3 ,3);

    glPushMatrix();
    glRotatef(22, 0, 0, 1);
    glScalef(1., 1., 0.6);
    gluCylinder(gluNewQuadric(), 1, 0.65, 1, 12, 6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 0., 0.5);
    glRotatef(55, 0, 0, 1);
    glScalef(0.8, 0.8, 0.63);
    gluCylinder(gluNewQuadric(), 1, 0.68, 1, 12, 6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 0., 1.07);
    glRotatef(-12, 0, 0, 1);
    glScalef(0.64, 0.64, 0.67);
    gluCylinder(gluNewQuadric(), 1, 0.6, 1, 12, 6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 0., 1.67);
     glRotatef(-95, 0, 0, 1);
    glScalef(0.48, 0.48, 0.78);
    gluCylinder(gluNewQuadric(), 1, 0.48, 1, 12, 6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 0., 2.3);
    glRotatef(-1, 0, 0, 1);
    glScalef(0.35, 0.35, 1.5);
    gluCylinder(gluNewQuadric(), 1, 0., 1, 12, 6);
    glPopMatrix();

    glPopMatrix();
}


void Pine :: drawPines() {

    glPushMatrix();
    glTranslatef(22., 22., 0.);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-17, 27.2, 0.);
    glRotatef(34, 0., 0., 1.);
    glScalef(0.9, 0.9, 0.95);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15, 22, 0.);
    glRotatef(22, 0., 0., 1.);
    glScalef(0.95, 0.95, 0.95);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-17, 16, 0.);
    glRotatef(22, 0., 0., 1.);
    glScalef(0.7, 0.7, 0.8);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20.5, 17, 0.);
    glRotatef(22, 0., 0., 1.);
    glScalef(0.5, 0.5, 0.65);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-21, 28, 0.);
    glRotatef(22, 0., 0., 1.);
    glScalef(0.5, 0.5, 0.65);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12, 30, 0.);
    glRotatef(22, 0., 0., 1.);
    glScalef(0.8, 0.8, 0.9);
    pine();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-8, 34, 0.);

    glPushMatrix();
    glRotatef(22, 0., 0., 1.);
    glScalef(0.6, 0.6, 0.7);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5, 1, 0.);
    glRotatef(22, 0., 0., 1.);
    glScalef(0.9, 0.9, 0.9);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 0, 0.);
    glRotatef(22, 0., 0., 1.);
    glScalef(0.8, 0.8, 0.9);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14, -3, 0.);
    glRotatef(22, 0., 0., 1.);
    glScalef(0.5, 0.5, 0.6);
    pine();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(18.8, 17.2, 0.);
    glRotatef(34, 0., 0., 1.);
    glScalef(0.65, 0.65, 0.7);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10., 27., 0.);
    glScalef(0.8, 0.8, 0.8);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(16., 27., 0.);
    glScalef(0.85, 0.85, 0.8);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12.5, 30., 0.);
    glScalef(0.5, 0.5, 0.65);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(21, 28., 0.);
    glScalef(0.6, 0.6, 0.7);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22., -22., 0.);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-22., -22., 0.);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-22., 22., 0.);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-16.5, -17., 0.);
    glRotatef(264, 0., 0., 1.);
    glScalef(0.9, 0.9, 1.1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-18.5, -11.5, 0.);
    glRotatef(224, 0., 0., 1.);
    glScalef(1, 1, 1.1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-13.5, -8.5, 0.);
    glRotatef(144, 0., 0., 1.);
    glScalef(0.85, 0.85, 0.8);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-23.5, -8.5, 0.);
    glRotatef(111, 0., 0., 1.);
    glScalef(0.8, 0.8, 0.8);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-24.5, 8.5, 0.);
    glRotatef(11, 0., 0., 1.);
    glScalef(0.8, 0.8, 0.8);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-29.5, 6.5, 0.);
    glRotatef(11, 0., 0., 1.);
    glScalef(0.7, 0.7, 0.7);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-29.5, 1.5, 0.);
    glRotatef(32, 0., 0., 1.);
    glScalef(0.92, 0.92, 1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-29.5, 12.5, 0.);
    glRotatef(82, 0., 0., 1.);
    glScalef(1, 1, 1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35, 5, 0.);
    glRotatef(24, 0., 0., 1.);
    glScalef(1.1, 1.1, 1.1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-23, 0, 0.);
    glRotatef(63, 0., 0., 1.);
    glScalef(1.1, 1.1, 1.1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(23, 0, 0.);
    glRotatef(46, 0., 0., 1.);
    glScalef(1.1, 1.1, 1.1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20, 4, 0.);
    glRotatef(38, 0., 0., 1.);
    glScalef(0.5, 0.5, 0.6);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(28, 3, 0.);
    glRotatef(46, 0., 0., 1.);
    glScalef(0.8, 0.8, 0.9);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(33, 7, 0.);
    glRotatef(86, 0., 0., 1.);
    glScalef(1, 1, 1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(36, 1, 0.);
    glRotatef(89, 0., 0., 1.);
    glScalef(0.9, 0.9, 0.9);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(25, -15, 0.);
    glRotatef(54, 0., 0., 1.);
    glScalef(1, 1, 1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -19, 0.);
    glRotatef(39, 0., 0., 1.);
    glScalef(0.8, 0.8, 0.9);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18, -5, 0.);
    glRotatef(10, 0., 0., 1.);
    glScalef(1.1, 1.1, 1.2);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5, -4, 0.);
    glRotatef(96, 0., 0., 1.);
    glScalef(1.1, 1.1, 1.2);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, -4, 0.);
    glRotatef(180, 0., 0., 1.);
    glScalef(0.8, 0.8, 0.8);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, -5, 0.);
    glRotatef(290, 0., 0., 1.);
    glScalef(0.6, 0.6, 0.6);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8, -11, 0.);
    glRotatef(273, 0., 0., 1.);
    glScalef(1., 1., 1.);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-17, -24, 0.);
    glRotatef(281, 0., 0., 1.);
    glScalef(0.7, 0.7, 0.7);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8, -12, 0.);
    glRotatef(91, 0., 0., 1.);
    glScalef(1, 1, 1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-27, -12, 0.);
    glRotatef(63, 0., 0., 1.);
    glScalef(0.85, 0.85, 0.9);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14, -12, 0.);
    glRotatef(87, 0., 0., 1.);
    glScalef(0.9, 0.9, 0.9);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18, -16, 0.);
    glRotatef(27, 0., 0., 1.);
    glScalef(0.7, 0.7, 0.8);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, -32, 0.);
    glRotatef(48, 0., 0., 1.);
    glScalef(0.7, 0.7, 0.75);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, -29, 0.);
    glRotatef(42, 0., 0., 1.);
    glScalef(0.9, 0.9, 0.9);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12, -30, 0.);
    glRotatef(348, 0., 0., 1.);
    glScalef(0.65, 0.65, 0.7);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-14, -34, 0.);
    glRotatef(318, 0., 0., 1.);
    glScalef(0.8, 0.8, 0.8);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, -29, 0.);
    glRotatef(268, 0., 0., 1.);
    glScalef(1, 1, 1);
    pine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-33, -12, 0.);
    glRotatef(38, 0., 0., 1.);
    glScalef(0.7, 0.7, 0.7);
    pine();
    glPopMatrix();

    // stumps :(
    glPushMatrix();
    glTranslatef(19, -27, 0.);
    glScalef(0.8, 0.8, 1.5);
    stump();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(17, -23, 0.);
    glScalef(0.7, 0.7, 1.2);
    stump();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(13, -17, 0.);
    glScalef(0.9, 0.9, 1.4);
    stump();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, -20, 0.);
    glScalef(0.75, 0.75, 1.3);
    stump();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12, -27, 0.);
    glScalef(0.8, 0.8, 1.25);
    stump();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15, -29, 0.);
    glScalef(0.85, 0.85, 1.3);
    stump();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7, -29, 0.);
    glScalef(0.7, 0.7, 1.3);
    stump();
    glPopMatrix();
}


void Pine :: stump() {

    glMaterialfv(GL_FRONT, GL_AMBIENT,    choco.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    choco.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   choco.specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   choco.shininess);
    glPushMatrix();
    gluCylinder(gluNewQuadric(), 1, 1, 1, 12, 1);
    glTranslatef(0., 0., 1.);
    glRotatef(180, 0., 0., 1.);
    gluDisk(gluNewQuadric(), 0.7, 1, 12, 6);
    glMaterialfv(GL_FRONT, GL_AMBIENT,    choco2.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    choco2.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   choco2.specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   choco2.shininess);
    gluDisk(gluNewQuadric(), 0, 0.7, 12, 6);
    glPopMatrix();
}
