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

#include "contrail.hpp"

#include <cmath>
#include <iostream>

contrail ::contrail(
    double originX,
    double originY,
    double originZ, int numClouds) :
    numClouds_(numClouds)
{

    this -> originX = originX;
    this -> originY = originY;
    this -> originZ = originZ;

    this -> positionX = 0;
    this -> positionY = 0;
    this -> positionZ = 0;

    randomizedTrail = true;

    aeroX = 0;
    aeroY = 0;
    aeroZ = 0;
}


// slot
void contrail :: randomizeTrail() {

    if (randomizedTrail) randomizedTrail = false;
    else randomizedTrail = true;
}

// draw cloud
void contrail ::cloud(struct material* bad_material, GLuint tex)
{

    glMaterialfv(GL_FRONT, GL_AMBIENT, bad_material->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bad_material->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bad_material->specular);
    glMaterialf(GL_FRONT, GL_SHININESS, bad_material->shininess);

    GLUquadric *quadric = gluNewQuadric();

    // generate texture coordinates for the quadric
    gluQuadricTexture(quadric, GL_TRUE);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    gluSphere(quadric, 1, 16, 16);
    glDisable(GL_TEXTURE_2D);

}

// spawn new cloud at specified position with given direction of movement and speed of the aeroplane. Direction is already computed.
void contrail :: spawn(double positionX, double positionY, double positionZ, double directionX, double directionY, double directionZ, int speed) {

    // delete any clouds_ of zero size.
    if (clouds_.size() >= numClouds_)
    {
        for (int i = 0; i < clouds_.size(); i++)
        {
            if (clouds_[i]->scale <= 0)
            {
                clouds_.erase(clouds_.begin() + i);
            }
        }
    }

    double scale;
    double zRand = 0;
    double xRand = 0;
    double yRand = 0;

    // X, Y and Z components of direction are obtained from aeroplane's current position/direction
    // if the randomized trail option is on, we slightly randomize each component
    // aeroplane's Z position is constant; if Z component is not randomized, clouds_ appear on a 2D plane.
    // because we also apply randomized momentum later, randomizing X and Y components increases the chaoticity/dispersion of the pattern.

    if (randomizedTrail) {
        zRand = std :: rand() % 20 - 10;
        zRand /= 100;
        xRand = zRand;
        yRand = zRand;

        // random initial size.
        scale = rand() % 10 + 5;
        scale /= 10;
    } else scale = 1;

    auto* bad_cloud = new ::cloud(
        positionX,
        positionY,
        positionZ,
        directionX + xRand,
        directionY + yRand,
        directionZ + zRand,
        scale,
        scale / numClouds_ / 10,
        randomizedTrail,
        speed
    );

    // new cloud will be rendered in the next frame
    clouds_.push_back(bad_cloud);
}

void contrail :: drawTrail(int speed, GLuint* tex, bool paused, int trailStyle) {

    if (paused) {
        // redraw clouds_ using their previously recorded positions
        for (auto inx : clouds_) {

            if (inx -> scale <= 0) continue;

            glPushMatrix();
            glTranslatef(inx -> positionX, inx -> positionY, inx -> positionZ);

            if (inx -> initial_scale < inx -> scale) glScalef(inx -> initial_scale, inx -> initial_scale, inx -> initial_scale);
            else glScalef(inx -> scale, inx -> scale, inx -> scale);

            glRotatef(inx -> rotationV, 0., 0., 1.);

            // single texture to all clouds_
            if (trailStyle >= 0) cloud(&veryBadCloud, tex[trailStyle]);
            // disarray
            else cloud(&veryBadCloud, tex[inx -> texId]);

            glPopMatrix();
        }
    } else {
        for (auto inx : clouds_) {
            if (inx -> scale <= 0) continue;
            glPushMatrix();

            // put each cloud in its position
            glTranslatef(inx -> positionX, inx -> positionY, inx -> positionZ);

            // make clouds_ quickly increase in size on spawn instead of suddenly appearing
            if (inx -> initial_scale < inx -> scale) {
                glScalef(inx -> initial_scale, inx -> initial_scale, inx -> initial_scale);
                inx -> initial_scale += 0.025 * speed;
            } else glScalef(inx -> scale, inx -> scale, inx -> scale);

            // check if any clouds_ are close to the aeroplane
            double afterEffectSphere = pow(inx -> positionX - aeroX, 2) + pow(inx -> positionY - aeroY, 2) + pow(inx -> positionZ - aeroZ, 2);

            // consider clouds_ that are further away if plane speed is high
            if (afterEffectSphere <= (20 * speed + 50) ) {
                // produce the effect
                inx -> momentum += (afterEffectSphere / 2000) * (double(speed) / 10);
                inx -> descaleFactor += (0.0005 * ((double(speed) + 10) / 10 ));
            }

            inx -> rotationV -= inx -> rotationR;
            glRotatef(inx -> rotationV, 0., 0., 1.);

            // if not disarray, apply one of the chosen textures to all clouds_
            if (trailStyle >= 0) cloud(&veryBadCloud, tex[trailStyle]);
            // else use each cloud's random texId to assign the corresponding texture
            else cloud(&veryBadCloud, tex[inx -> texId]);

            glPopMatrix();
            inx -> descale(inx -> descaleFactor);
            inx -> updatePosition();
        }
    }
}

// update current aeroplane position
// necessary for computing which clouds_ are near the aeroplane
void contrail :: afterEffect(double aeroX, double aeroY, double aeroZ) {

    this -> aeroX = aeroX;
    this -> aeroY = aeroY;
    this -> aeroZ = aeroZ;

}
