#pragma once

class cloud {

public:
    cloud(
        double positionX,
        double positionY,
        double positionZ,
        double directionX,
        double directionY,
        double directionZ,
        double scale,
        double descaleFactor,
        bool randomized,
        int speed
    );

    double positionX;
    double positionY;
    double positionZ;

    double directionX;
    double directionY;
    double directionZ;

    double scale;
    double initial_scale;
    double descaleFactor;
    double momentum;

    int speed;
    int texId;

    double rotationV;
    double rotationR;

    void updateCloud(double positionX, double positionY, double positionZ, double scale);
    void updatePosition();
    void descale(double scale);
};
