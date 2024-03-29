#include <GL/glu.h>
#include <cmath>
#include <iostream>
#include "CloudTrail.h"

CloudTrail :: CloudTrail(double originX, double originY, double originZ, int cloudsAmount) : cloudsAmount(cloudsAmount) {

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
void CloudTrail :: randomizeTrail() {

    if (randomizedTrail) randomizedTrail = false;
    else randomizedTrail = true;
}

// draw cloud
void CloudTrail :: cloud(materialStruct* material, GLuint tex) {

    glMaterialfv(GL_FRONT, GL_AMBIENT,    material -> ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    material -> diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   material -> specular);
    glMaterialf( GL_FRONT, GL_SHININESS,  material -> shininess);

    GLUquadric *quadric = gluNewQuadric();

    // generate texture coordinates for the quadric
    gluQuadricTexture(quadric, GL_TRUE);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    gluSphere(quadric, 1, 16, 16);
    glDisable(GL_TEXTURE_2D);

}

// spawn new cloud at specified position with given direction of movement and speed of the aeroplane. Direction is already computed.
void CloudTrail :: spawn(double positionX, double positionY, double positionZ, double directionX, double directionY, double directionZ, int speed) {

    // delete any clouds of zero size.
    if (clouds.size() >= cloudsAmount) for (int i = 0; i < clouds.size(); i++) if (clouds[i] -> scale <= 0) clouds.erase(clouds.begin() + i);

    double scale;
    double zRand = 0;
    double xRand = 0;
    double yRand = 0;

    // X, Y and Z components of direction are obtained from aeroplane's current position/direction
    // if the randomized trail option is on, we slightly randomize each component
    // aeroplane's Z position is constant; if Z component is not randomized, clouds appear on a 2D plane.
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

    Cloud* cloud = new Cloud(positionX, positionY, positionZ, directionX + xRand, directionY + yRand, directionZ + zRand, scale, scale / cloudsAmount / 10, randomizedTrail, speed);

    // new cloud will be rendered in the next frame
    clouds.push_back(cloud);
}

void CloudTrail :: drawTrail(int speed, GLuint* tex, bool paused, int trailStyle) {

    if (paused) {
        // redraw clouds using their previously recorded positions
        for (auto inx : clouds) {

            if (inx -> scale <= 0) continue;

            glPushMatrix();
            glTranslatef(inx -> positionX, inx -> positionY, inx -> positionZ);

            if (inx -> initial_scale < inx -> scale) glScalef(inx -> initial_scale, inx -> initial_scale, inx -> initial_scale);
            else glScalef(inx -> scale, inx -> scale, inx -> scale);

            glRotatef(inx -> rotationV, 0., 0., 1.);

            // single texture to all clouds
            if (trailStyle >= 0) cloud(&veryBadCloud, tex[trailStyle]);
            // disarray
            else cloud(&veryBadCloud, tex[inx -> texId]);

            glPopMatrix();
        }
    } else {
        for (auto inx : clouds) {
            if (inx -> scale <= 0) continue;
            glPushMatrix();

            // put each cloud in its position
            glTranslatef(inx -> positionX, inx -> positionY, inx -> positionZ);

            // make clouds quickly increase in size on spawn instead of suddenly appearing
            if (inx -> initial_scale < inx -> scale) {
                glScalef(inx -> initial_scale, inx -> initial_scale, inx -> initial_scale);
                inx -> initial_scale += 0.025 * speed;
            } else glScalef(inx -> scale, inx -> scale, inx -> scale);

            // check if any clouds are close to the aeroplane
            double afterEffectSphere = pow(inx -> positionX - aeroX, 2) + pow(inx -> positionY - aeroY, 2) + pow(inx -> positionZ - aeroZ, 2);

            // consider clouds that are further away if plane speed is high
            if (afterEffectSphere <= (20 * speed + 50) ) {
                // produce the effect
                inx -> momentum += (afterEffectSphere / 2000) * (double(speed) / 10);
                inx -> descaleFactor += (0.0005 * ((double(speed) + 10) / 10 ));
            }

            inx -> rotationV -= inx -> rotationR;
            glRotatef(inx -> rotationV, 0., 0., 1.);

            // if not disarray, apply one of the chosen textures to all clouds
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
// necessary for computing which clouds are near the aeroplane
void CloudTrail :: afterEffect(double aeroX, double aeroY, double aeroZ) {

    this -> aeroX = aeroX;
    this -> aeroY = aeroY;
    this -> aeroZ = aeroZ;

}
