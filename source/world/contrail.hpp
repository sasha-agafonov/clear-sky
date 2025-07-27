#pragma once

#include <QObject>
#include <vector>

#include "utilities/materials.hpp"
#include "world/cloud.hpp"

#include <QtGui/qopengl.h> 

class contrail : public QObject {

    Q_OBJECT

public slots:
    void randomizeTrail();

public:
    contrail(double originX, double originY, double originZ, int cloudsAmount);

    void cloud(struct material * bad_material, GLuint tex);
    void spawn(double positionX, double positionY, double positionZ, double directionX, double directionY, double directionZ, int speed);
    void drawTrail(int speed, GLuint* tex, bool paused, int trailStyle);
    void afterEffect(double aeroX, double aeroY, double aeroZ);

    int numClouds_ = {};
    bool randomizedTrail;

private:
    double aeroX;
    double aeroY;
    double aeroZ;

    double positionX;
    double positionY;
    double positionZ;

    double originX;
    double originY;
    double originZ;

    // keep all alive clouds here
    std :: vector <::cloud*> clouds_;

};

