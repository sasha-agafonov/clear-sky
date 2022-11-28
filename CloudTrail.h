#ifndef CLOUDTRAIL_H
#define CLOUDTRAIL_H

#include <QGLWidget>
#include <QObject>
#include <vector>

#include "Materials.h"
#include "Cloud.h"

class CloudTrail : public QGLWidget {

    Q_OBJECT

public slots:
    void randomizeTrail();

public:
    CloudTrail(double originX, double originY, double originZ, int cloudsAmount);

    void cloud(materialStruct* material, GLuint tex);
    void spawn(double positionX, double positionY, double positionZ, double directionX, double directionY, double directionZ, int speed);
    void drawTrail(int speed, GLuint* tex, bool paused, int trailStyle);
    void afterEffect(double aeroX, double aeroY, double aeroZ);

    int cloudsAmount;
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
    std :: vector <Cloud*> clouds;

};

#endif // CLOUDTRAIL_H
