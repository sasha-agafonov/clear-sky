#include <cmath>
#include "SimpleShape.h"

SimpleShape :: SimpleShape() {}

void SimpleShape :: plane(materialStruct* material) {

    glMaterialfv(GL_FRONT, GL_AMBIENT,   material -> ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   material -> diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  material -> specular);
    glMaterialf( GL_FRONT, GL_SHININESS, material -> shininess);

    GLfloat normals[3] = {0., 0., 1.};

    glNormal3fv(normals);
    glBegin(GL_POLYGON);
      glVertex3f( 1.0, -1.0,  1.0);
      glVertex3f( 1.0,  1.0,  1.0);
      glVertex3f(-1.0,  1.0,  1.0);
      glVertex3f(-1.0, -1.0,  1.0);
    glEnd();
}

void SimpleShape :: eqTriangle(materialStruct* material) {
    glMaterialfv(GL_FRONT, GL_AMBIENT,   material -> ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   material -> diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  material -> specular);
    glMaterialf( GL_FRONT, GL_SHININESS, material -> shininess);

    GLfloat normals[3] = {0., 0., 1};

    glNormal3fv(normals);
    glBegin(GL_TRIANGLES);
        glVertex3f( 1.0, -1.0,  1.0);
        glVertex3f( 1.0,  1.0,  1.0);
        glVertex3f(-1.0,  1.0,  1.0);
    glEnd();
}

void SimpleShape :: cube(materialStruct* material) {

     GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.} };

    // Here we have permuted the first normal array
    // GLfloat normals[][3] = {  {-1., 0., 0.}, {0., 0., 1.}, {1., 0. ,0.}, {0., 0., -1.} };

    glMaterialfv(GL_FRONT, GL_AMBIENT,   material -> ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   material -> diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  material -> specular);
    glMaterialf( GL_FRONT, GL_SHININESS, material -> shininess);

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

void SimpleShape :: cone(materialStruct* material, int nFaces) {

    if (nFaces < 3) return;

    glMaterialfv(GL_FRONT, GL_AMBIENT,    material->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    material->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   material->specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   material->shininess);


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


void SimpleShape :: cylinder(materialStruct* material, int nFaces) {

//    if (nFaces == 1 || nFaces == 2 ) {
//        this -> plane(material);
//        return;
//    } else if (nFaces <= 0) return;

    glMaterialfv(GL_FRONT, GL_AMBIENT,   material -> ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   material -> diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  material -> specular);
    glMaterialf( GL_FRONT, GL_SHININESS, material -> shininess);

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


