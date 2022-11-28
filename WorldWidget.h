#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1

#include <QGLWidget>
#include <QObject>
#include <QImage>
#include <QGLFormat>

#include "Materials.h"
#include "CloudTrail.h"
#include "Shape.h"
#include "Aero.h"
#include "Turbo.h"
#include "House.h"
#include "Pine.h"
#include "Fence.h"

class Aero;
class CloudTrail;
class Shape;
class Turbo;
class House;
class Pine;
class Fence;


class WorldWidget : public QGLWidget {

    Q_OBJECT

public:
    WorldWidget(QGLFormat format, QWidget *parent);

    CloudTrail* trail;

public slots:

    void updateVerticalView(int ang);
    void updateHorizontalView(int ang);
    void updateZoom(int zoom);
    void updateScene();
    void changeTrajectory(int rad);
    void changeAircraftSpeed(int speed);
    void setCloudsAmount(int amount);
    void setCloudSpawnRate(int rate);
    void changeAeroStyle(int selection);
    void changeCloudStyle(int selection);
    void doAileronRoll();
    void shadeSmooth();
    void shutTurbo();
    void pause();


protected:

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:

    Shape* shape2;
    Aero* aero;
    Turbo* turbo;
    House* house;
    Pine* pine;
    Fence* fence;

    GLuint textures[4];

    bool locked, manouvering, smooth, turboOff;

    // when the scene is paused and when the camera is moved.
    // used to avoid updating object animations when not needed.
    // cameraMovement is pretty much the same as paused, except that it acts for one frame only.
    bool paused, cameraMovement;

    int hViewAng, vViewAng,  trajectoryRad;
    int cloudsAmount, cloudSpawnRate;
    int cloudStyle, aeroStyle;
    float zoom;

    int time;
    double arcLen, positionAng, rollAng;

};

#endif

