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


#include "turbo.hpp"
#include <cmath>

turbo::turbo()
{
    off = false;
    rAng = 0;
}

void turbo::turbo_inner(bool off, bool paused)
{

    if (!off && !paused) rAng++;

    glMaterialfv(GL_FRONT, GL_AMBIENT,    whitesh.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    whitesh.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   whitesh.specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   whitesh.shininess);

    glPushMatrix();
    glScalef(1.,1.,16);
    gluCylinder(gluNewQuadric(), 1, 0.5, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 1.5, 16.);
    glRotatef(90, 1, 0, 0);
    glRotatef(-rAng, 0., 0.,1);

    glPushMatrix();
    glScalef(1, 1, 3);
    gluCylinder(gluNewQuadric(), 0.6, 0.6, 1, 24, 24);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 3);
    gluDisk(gluNewQuadric(), 0, 0.6, 24, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.5, 0, 0);
    glRotatef(90, 0., 0., 1.);
    glRotatef(30, 0, 1, 0);
    glScalef(0.4, 5, 0.2);
    gluSphere(gluNewQuadric(), 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(120, 0., 0. ,1);
    glTranslatef(4.5, 0, 0);
    glRotatef(90, 0., 0., 1.);
    glRotatef(30, 0, 1, 0);
    glScalef(0.4, 5, 0.2);
    gluSphere(gluNewQuadric(), 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(240, 0., 0. ,1);
    glTranslatef(4.5, 0, 0);
    glRotatef(90, 0., 0., 1.);
    glRotatef(30, 0, 1, 0);
    glScalef(0.4, 5, 0.2);
    gluSphere(gluNewQuadric(), 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0., 1., 0);
    gluCylinder(gluNewQuadric(), 0.6, 0.4, 0.5, 24, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 0., -0.5);
    glRotatef(180, 0., 1., 0);
    gluDisk(gluNewQuadric(), 0, 0.4, 24, 10);
    glPopMatrix();

    glPopMatrix();

}
