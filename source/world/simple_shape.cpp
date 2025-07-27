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

#include <cmath>
#include "simple_shape.hpp"

simple_shape ::simple_shape() {}

void simple_shape ::plane(struct material* bad_material)
{

    glMaterialfv(GL_FRONT, GL_AMBIENT, bad_material->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bad_material->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bad_material->specular);
    glMaterialf(GL_FRONT, GL_SHININESS, bad_material->shininess);

    GLfloat normals[3] = {0., 0., 1.};

    glNormal3fv(normals);
    glBegin(GL_POLYGON);
      glVertex3f( 1.0, -1.0,  1.0);
      glVertex3f( 1.0,  1.0,  1.0);
      glVertex3f(-1.0,  1.0,  1.0);
      glVertex3f(-1.0, -1.0,  1.0);
    glEnd();
}

void simple_shape ::eqTriangle(struct material* bad_material)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, bad_material->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bad_material->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  bad_material -> specular);
    glMaterialf(GL_FRONT, GL_SHININESS, bad_material->shininess);

    GLfloat normals[3] = {0., 0., 1};

    glNormal3fv(normals);
    glBegin(GL_TRIANGLES);
        glVertex3f( 1.0, -1.0,  1.0);
        glVertex3f( 1.0,  1.0,  1.0);
        glVertex3f(-1.0,  1.0,  1.0);
    glEnd();
}

void simple_shape ::cube(struct material* bad_material)
{

     GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.} };

    // Here we have permuted the first normal array
    // GLfloat normals[][3] = {  {-1., 0., 0.}, {0., 0., 1.}, {1., 0. ,0.}, {0., 0., -1.} };

    glMaterialfv(GL_FRONT, GL_AMBIENT, bad_material->ambient);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, bad_material->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bad_material->specular);
     glMaterialf(GL_FRONT, GL_SHININESS, bad_material->shininess);

    glNormal3fv(normals[0]);
    glBegin(GL_POLYGON);
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0,  1.0);
    glEnd();

    glNormal3fv(normals[3]);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f(-1.0,  1.0, -1.0);
    glEnd();

    glNormal3fv(normals[2]);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f( 1.0, -1.0, 1.0);
    glVertex3f( 1.0,  1.0, 1.0);
    glVertex3f(-1.0,  1.0, 1.0);
    glEnd();

    glNormal3fv(normals[1]);
    glBegin(GL_POLYGON);
    glVertex3f( -1.0, -1.0,  1.0);
    glVertex3f( -1.0, -1.0, -1.0);
    glVertex3f( -1.0,  1.0, -1.0);
    glVertex3f( -1.0,  1.0,  1.0);
    glEnd();
}

void simple_shape ::cone(struct material* bad_material, int nFaces)
{

    if (nFaces < 3) return;

    glMaterialfv(GL_FRONT, GL_AMBIENT, bad_material->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bad_material->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bad_material->specular);
    glMaterialf(GL_FRONT, GL_SHININESS, bad_material->shininess);


    float x, y, x_prev, y_prev;

    for (int i = 0; i < nFaces; i++) {
        x_prev = sin(2 * PI * (i/nFaces));
        y_prev = cos(2 * PI * (i/nFaces));
        x = sin(2 * PI * ((i + 1)/nFaces));
        y = cos(2 * PI * ((i + 1)/nFaces));

        glBegin(GL_TRIANGLES);
          glVertex3f(x_prev,  y_prev,  -1.);
          glVertex3f(x,  y, -1.);
          glVertex3f(0.,  0., 1.);
        glEnd();
    }
}


void simple_shape ::cylinder(struct material* bad_material, int nFaces)
{

//    if (nFaces == 1 || nFaces == 2 ) {
//        this -> plane(material);
//        return;
//    } else if (nFaces <= 0) return;

    glMaterialfv(GL_FRONT, GL_AMBIENT, bad_material->ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, bad_material->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bad_material->specular);
glMaterialf(GL_FRONT, GL_SHININESS, bad_material->shininess);

    float x, y, x_prev, y_prev;

    for (int i = 0 ; i < nFaces; i++) {

        x_prev = sin(2 * PI * (i/nFaces));
        y_prev = cos(2 * PI * (i/nFaces));
        x = sin(2 * PI * ((i + 1)/nFaces));
        y = cos(2 * PI * ((i + 1)/nFaces));

        glBegin(GL_POLYGON);
        glVertex3f(x_prev,  y_prev,  1.0);
        glVertex3f(x_prev,  y_prev, -1.0);
        glVertex3f(x,  y, -1.0);
        glVertex3f(x,  y,  1.0);
        glEnd();
    }
}


