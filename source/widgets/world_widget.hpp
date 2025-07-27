#pragma once

#include <QOpenGLWidget>
#include <QSurfaceFormat>
#include <QImage>

#include "utilities/materials.hpp"
#include "world/contrail.hpp"
#include "world/shape.hpp"
#include "world/aero.hpp"
#include "world/turbo.hpp"
#include "world/house.hpp"
#include "world/pine.hpp"
#include "world/fence.hpp"

#include <QtGui/qopengl.h> 

class Aero;
class CloudTrail;
class Shape;
class Turbo;
class House;
class Pine;
class Fence;

class world_widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit world_widget(
        QSurfaceFormat const& format = QSurfaceFormat{},
        QWidget* parent = nullptr
    );

    contrail* trail_;

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
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    shape* shape2_;
    aero* aero_;
    turbo* turbo_;
    house* house_;
    pine* pine_;
    fence* fence_;

    unsigned int textures[4];

    bool locked, manouvering, smooth, turboOff;
    bool paused, cameraMovement;

    int hViewAng, vViewAng, trajectoryRad;
    int cloudsAmount, cloudSpawnRate;
    int cloudStyle, aeroStyle;
    float zoom;

    int time;
    double arcLen, positionAng, rollAng;
};
