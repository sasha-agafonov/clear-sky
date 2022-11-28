#include <GL/glu.h>
#include <cmath>

#include "Shape.h"

Shape :: Shape() {}

void Shape :: icosahedron(materialStruct* material) {

    glMaterialfv(GL_FRONT, GL_AMBIENT,   material -> ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   material -> diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  material -> specular);
    glMaterialf( GL_FRONT, GL_SHININESS, material -> shininess);

    // for storing all points, two pentagons of five points each plus the top and the bottom
    float bottom_pentagon[15];
    float top_pentagon[15];
    float top_point[3];
    float bottom_point[3];

    // circle center
    float xp = 0;
    float yp = 0;
    float zp = -0.5;

    // construct a decagon on a circle with radius 1 and center at 0, 0, -0.5, i.e. locate 10 evenly spaced points on a circle
    // we choose this so the icosahedron is centered at 0, 0, 0.

    for (int i = 0; i < 10; i++) {

        xp = std :: cos(((i * 36)) * PI / 180);
        yp = std :: sin(((i * 36)) * PI / 180);

        // bottom pentagon, 5 points. Use every second point of the decagon.
        if (i % 2 == 0) {
            bottom_pentagon[i / 2 * 3] = xp;
            bottom_pentagon[i / 2 * 3 + 1] = yp;
            bottom_pentagon[i / 2 * 3 + 2] = zp;

        // top pentagon, 5 points. each point is shifted up by the value of the radius of the circle.
        } else {
            top_pentagon[i / 2 * 3] = xp;
            top_pentagon[i / 2 * 3 + 1] = yp;
            top_pentagon[i / 2 * 3 + 2] = zp + 1;
        }
    }

    // now we have located all but two points: top and bottom.
    // we know that each point has coordiantes 0, 0 for its x and y components.
    // we can use the icosahedron's property of all points being the same distance away from the center, 0, 0, 0 in our case.
    // so the z coordinates of top and bottom points become the positive and the negative
    // distances of any other point from the center at 0, 0, 0.

    top_point[0] = 0;
    top_point[1] = 0;
    top_point[2] = abs(vectorLength(bottom_pentagon[0], bottom_pentagon[1], bottom_pentagon[2]));

    bottom_point[0] = 0;
    bottom_point[1] = 0;
    bottom_point[2] = -abs(vectorLength(bottom_pentagon[0], bottom_pentagon[1], bottom_pentagon[2]));

    // all points located, now we can draw
    // we start from the bottom


    // for each normal, compute the normal between two vectors forming two sides of the corresponding triangle.
    double ux, uy, uz;
    double vx, vy, vz;
    GLfloat nx, ny, nz;

    // 20 faces, ccw orientation
    for (int j = 0; j < 20; j++) {
        // connect bottom point and bottom pentagon
        if (j < 5) {

            // normals
            ux = bottom_pentagon[((j + 1) * 3) % 15] - bottom_point[0];
            uy = bottom_pentagon[((j + 1) * 3 + 1) % 15 ] - bottom_point[1];
            uz = bottom_pentagon[((j + 1) * 3 + 2) % 15 ] - bottom_point[2];

            vx = bottom_pentagon[j * 3 % 15] - bottom_point[0];
            vy = bottom_pentagon[(j * 3 + 1) % 15 ] - bottom_point[1];
            vz = bottom_pentagon[(j * 3 + 2) % 15 ]  - bottom_point[2];

            nx = uy * vz - uz * vy;
            ny = uz * vx - ux * vz;
            nz = ux * vy - uy * vx;


            // set normals, draw the triangle
            glBegin(GL_TRIANGLES);
            glNormal3f( nx, ny, nz );
            glVertex3f( bottom_point[0], bottom_point[1], bottom_point[2]);
            glNormal3f( nx, ny, nz ); // probably a useless repeat for flat shading
            glVertex3f( bottom_pentagon[((j + 1) * 3) % 15], bottom_pentagon[((j + 1) * 3 + 1) % 15 ], bottom_pentagon[((j + 1) * 3 + 2) % 15 ]);
            glNormal3f( nx, ny, nz );
            glVertex3f( bottom_pentagon[j * 3 % 15],  bottom_pentagon[(j * 3 + 1) % 15 ], bottom_pentagon[(j * 3 + 2) % 15 ]);
            glEnd();
        }

        // body the triangles connectng the two pentagons
        else if (j >= 5 && j < 15) {

            // two vertices from bottom polygon, one from top
            if (j % 2 != 0) {

                ux = bottom_pentagon[j * 3 % 15] - top_pentagon[j * 3 % 15];
                uy = bottom_pentagon[(j * 3 + 1) % 15] - top_pentagon[(j * 3 + 1) % 15];
                uz = bottom_pentagon[(j * 3 + 2) % 15] - top_pentagon[(j * 3 + 2) % 15] ;

                vx = bottom_pentagon[((j + 1) * 3) % 15] - top_pentagon[j * 3 % 15];
                vy = bottom_pentagon[((j + 1) * 3 + 1) % 15] - top_pentagon[(j * 3 + 1) % 15];
                vz = bottom_pentagon[((j + 1) * 3 + 2) % 15] - top_pentagon[(j * 3 + 2) % 15] ;

                nx = uy * vz - uz * vy;
                ny = uz * vx - ux * vz;
                nz = ux * vy - uy * vx;

                glBegin(GL_TRIANGLES);
                glNormal3f( nx, ny, nz);
                glVertex3f( top_pentagon[j * 3 % 15], top_pentagon[(j * 3 + 1) % 15], top_pentagon[(j * 3 + 2) % 15] );
                glNormal3f( nx, ny, nz);
                glVertex3f( bottom_pentagon[j * 3 % 15], bottom_pentagon[(j * 3 + 1) % 15], bottom_pentagon[(j * 3 + 2) % 15]);
                glNormal3f( nx, ny, nz);
                glVertex3f( bottom_pentagon[((j + 1) * 3) % 15], bottom_pentagon[((j + 1) * 3 + 1) % 15], bottom_pentagon[((j + 1) * 3 + 2) % 15]);

                glEnd();

            // two vertices from top polygon, one from bottom
            } else {

                ux = bottom_pentagon[((j + 1) * 3) % 15] - top_pentagon[j * 3 % 15];
                uy = bottom_pentagon[((j + 1) * 3 + 1) % 15] - top_pentagon[(j * 3 + 1) % 15];
                uz = bottom_pentagon[((j + 1) * 3 + 2) % 15] - top_pentagon[(j * 3 + 2) % 15];

                vx = top_pentagon[((j + 1) * 3) % 15] - top_pentagon[j * 3 % 15];
                vy = top_pentagon[((j + 1) * 3 + 1) % 15] - top_pentagon[(j * 3 + 1) % 15];
                vz = top_pentagon[((j + 1) * 3 + 2) % 15] - top_pentagon[(j * 3 + 2) % 15];

                nx = uy * vz - uz * vy;
                ny = uz * vx - ux * vz;
                nz = ux * vy - uy * vx;

                glBegin(GL_TRIANGLES);

                glNormal3f( nx, ny, nz);
                glVertex3f( top_pentagon[j * 3 % 15], top_pentagon[(j * 3 + 1) % 15], top_pentagon[(j * 3 + 2) % 15]);
                glNormal3f( nx, ny, nz);
                glVertex3f( bottom_pentagon[((j + 1) * 3) % 15], bottom_pentagon[((j + 1) * 3 + 1) % 15], bottom_pentagon[((j + 1) * 3 + 2) % 15]);
                glNormal3f( nx, ny, nz);
                glVertex3f( top_pentagon[((j + 1) * 3) % 15], top_pentagon[((j + 1) * 3 + 1) % 15], top_pentagon[((j + 1) * 3 + 2) % 15]);

                glEnd();
            }
        }

        // connecing top point and top polygon
        else {


            vx = top_pentagon[((j + 1) * 3) % 15] - top_pentagon[j * 3 % 15];
            vy = top_pentagon[((j + 1) * 3 + 1) % 15] - top_pentagon[(j * 3 + 1) % 15];
            vz = top_pentagon[((j + 1) * 3 + 2) % 15] - top_pentagon[(j * 3 + 2) % 15];

            ux = top_point[0] - top_pentagon[j * 3 % 15];
            uy = top_point[1] - top_pentagon[(j * 3 + 1) % 15];
            uz = top_point[2] - top_pentagon[(j * 3 + 2) % 15];

            nx = uy * vz - uz * vy;
            ny = uz * vx - ux * vz;
            nz = ux * vy - uy * vx;

            glBegin(GL_TRIANGLES);

            glNormal3f( -nx, -ny, -nz);
            glVertex3f( top_pentagon[j * 3 % 15],  top_pentagon[(j * 3 + 1) % 15], top_pentagon[(j * 3 + 2) % 15]);
            glNormal3f( -nx, -ny, -nz);
            glVertex3f( top_pentagon[((j + 1) * 3) % 15],  top_pentagon[((j + 1) * 3 + 1) % 15], top_pentagon[((j + 1) * 3 + 2) % 15]);
            glNormal3f( -nx, -ny, -nz);
            glVertex3f( top_point[0], top_point[1], top_point[2]);

            glEnd();
        }
    }
}


double Shape :: vectorLength(double a, double b, double c) { return (sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2))); }


void Shape :: cube(materialStruct* material) {

    GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.}, {0., 1., 0.}, {0., -1., 0.} };

    glMaterialfv(GL_FRONT, GL_AMBIENT,   material -> ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   material -> diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  material -> specular);
    glMaterialf( GL_FRONT, GL_SHININESS, material -> shininess);

    // ccw orientation
    glNormal3fv(normals[0]);
    glBegin(GL_POLYGON);
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0,  1.0);
    glEnd();

    glNormal3fv(normals[3]);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
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
    glVertex3f( -1.0,  1.0,  1.0);
    glVertex3f( -1.0,  1.0, -1.0);
    glVertex3f( -1.0, -1.0, -1.0);
    glVertex3f( -1.0, -1.0,  1.0);
    glEnd();

    glNormal3fv(normals[4]);
    glBegin(GL_POLYGON);
    glVertex3f(  1.0,  1.0,  1.0);
    glVertex3f(  1.0,  1.0, -1.0);
    glVertex3f( -1.0,  1.0, -1.0);
    glVertex3f( -1.0,  1.0,  1.0);
    glEnd();

    glNormal3fv(normals[5]);
    glBegin(GL_POLYGON);
    glVertex3f( -1.0, -1.0,  1.0);
    glVertex3f( -1.0, -1.0, -1.0);
    glVertex3f(  1.0, -1.0, -1.0);
    glVertex3f(  1.0, -1.0,  1.0);
    glEnd();

}

void Shape :: triangularPrism(materialStruct* material) {

    GLfloat normals[][3] = { {0., 0., 1.}, {1., 0., 0.}, {-0.5, 0., -0.5}, {0., 1., 0.}, {0., -1., 0.} };

    glMaterialfv(GL_FRONT, GL_AMBIENT,    material->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    material->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   material->specular);
    glMaterialf( GL_FRONT, GL_SHININESS,  material->shininess);

    // ccw
    glNormal3fv(normals[0]);
    glBegin(GL_POLYGON);
    glVertex3f( 1.0,  1.0, 1.0);
    glVertex3f(-1.0,  1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f( 1.0, -1.0, 1.0);
    glEnd();

    glNormal3fv(normals[1]);
    glBegin(GL_POLYGON);
    glVertex3f( 1.0,  1.0,  1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0,  1.0);
    glEnd();

    glNormal3fv(normals[2]);
    glBegin(GL_POLYGON);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0,  1.0);
    glVertex3f(-1.0,  1.0,  1.0);
    glEnd();

    glNormal3fv(normals[3]);
    glBegin(GL_TRIANGLES);
    glVertex3f( 1.0,  1.0,  1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f(-1.0,  1.0,  1.0);
    glEnd();

    glNormal3fv(normals[4]);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0, -1.0,  1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0,  1.0);
    glEnd();

}

void Shape :: hollowCylinder(materialStruct* material, int segments, int rings, double innerRad) {

    glMaterialfv(GL_FRONT, GL_AMBIENT,    material->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    material->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   material->specular);
    glMaterialf( GL_FRONT, GL_SHININESS,  material->shininess);

    GLUquadric *quadric;
    quadric = gluNewQuadric();

    // inner cylinder, flip normals
    gluQuadricOrientation(quadric, GLU_INSIDE);
    glPushMatrix();
    glScalef(innerRad, innerRad, 1.);
    glTranslatef(0., 0., -1);
    gluCylinder(quadric, 1, 1, 2, segments, rings);
    glPopMatrix();

    // outer cylinder, flip back
    quadric = gluNewQuadric();
    gluQuadricOrientation(quadric, GLU_OUTSIDE);
    glPushMatrix();
    glTranslatef(0., 0., -1);
    gluCylinder(quadric, 1, 1, 2, segments, rings);

    // disk for connecting cylinders
    // only this part will be visible so I am not using a second disk for the other side
    glTranslatef(0., 0., 2.);
    gluDisk(gluNewQuadric(), innerRad, 1., segments, 4.);
    glPopMatrix();

}
