#include "cloud.hpp"

#include <cmath>
#include <cstdlib>

static const float PI = 3.1415926535;

// keeps all information about a particular cloud
cloud :: cloud(double positionX, double positionY, double positionZ, double directionX, double directionY, double directionZ, double scale, double descaleFactor, bool randomized, int speed) {

    // where it is
    this -> positionX = positionX;
    this -> positionY = positionY;
    this -> positionZ = positionZ;

    // where to move
    this -> directionX = directionX;
    this -> directionY = directionY;
    this -> directionZ = directionZ;

    // what size
    this -> scale = scale;
    this -> initial_scale = 0.5;
    this -> descaleFactor = descaleFactor;

    // speed, texture id if "disarray" style is chosen
    this -> speed = speed;
    this -> texId = rand() % 3;

    // randomize some stuff if the option is enabled
    if (randomized) {

        // used to compute how much initial speed of cloud decreases
        this -> momentum = rand() % 40 + 90;
        this -> momentum /= 100;

        // for textures, if randomized
        rotationV = rand() % 360;
        rotationR = (double)(rand() % 360) / 100;

    } else {
        momentum = 1.;
        rotationV = 0;
        rotationR = 0;
    }
}

// prepare the cloud for next frame
void cloud :: updatePosition() {
    positionX = positionX - (directionX / (11.5 - 0.75 * speed)) * momentum;
    positionY = positionY - (directionY / (11.5 - 0.75 * speed)) * momentum;
    positionZ = positionZ - (directionZ / (11.5 - 0.75 * speed)) * momentum;
    if (momentum > 0) {
        if (momentum - 0.0025 > 0) momentum -= 0.0025;
        else momentum = 0;
    }
}

// decrease current scale of cloud
void cloud :: descale(double scale) { this -> scale = this -> scale - scale; }
