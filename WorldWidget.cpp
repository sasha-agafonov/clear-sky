#include <GL/glu.h>
#include <QGLWidget>
#include <QTimer>
#include <QTime>
#include <QDir>

#include <cmath>
#include <cstdlib>
#include <iostream>

#include "WorldWidget.h"

WorldWidget :: WorldWidget(QGLFormat format, QWidget* parent) : QGLWidget(parent), hViewAng(260), vViewAng(41), zoom(0.1), time(0) {

    setFormat(format);
    trajectoryRad = 40;
    cloudsAmount = 10;
    cloudSpawnRate = 1;
    paused = false;
    locked = false;
    manouvering = false;
    smooth = false;
    turboOff = false;
    cameraMovement = false;
    trail = new CloudTrail(0., 0., 0., cloudsAmount);
    shape2 = new Shape();
    aero = new Aero(2);
    turbo = new Turbo();
    house = new House();
    pine = new Pine();
    fence = new Fence();
    positionAng = 0;
    arcLen = 0;
    aeroStyle = 0;
    cloudStyle = 0;

}


void WorldWidget :: initializeGL() {

    // bg
    glClearColor(0.5, 0.6, 0.9, 0.0);



    // we need 3 textures
    glGenTextures (3, textures);
    glBindTexture ( GL_TEXTURE_2D, textures[0] );

    QImage image, image2;

    GLsizei width, height;

    // search for the image. Qt views the build directory as the current one, so we also look outside.
    if (!image.load("./markus.ppm") && !image.load("../world/markus.ppm")) std :: cout << "markus.ppm is missing";

    // glsizei width + height
    width = image.width();
    height = image.height();

    // convert
    image2 = this -> convertToGLFormat(image);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image2.bits());

    // mirrored repeat wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    // linear minification/magnificaton
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // next texture
    glBindTexture ( GL_TEXTURE_2D, textures[1] );

    if (!image.load("./Marc_Dekamps.ppm") && !image.load("../world/Marc_Dekamps.ppm")) std :: cout << "Marc_Dekaps.ppm cannot be loaded";

    width = image.width();
    height = image.height();
    image2 = this -> convertToGLFormat(image);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image2.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // next texture
    glBindTexture ( GL_TEXTURE_2D, textures[2] );

    if (!image.load("./Mercator-projection.ppm") && !image.load("../world/Mercator-projection.ppm")) std :: cout << "Mercator-projection.ppm is not found";

    width = image.width();
    height = image.height();
    image2 = this->convertToGLFormat(image);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image2.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

}



void WorldWidget :: resizeGL(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // directional
    GLfloat light_pos[] = {-1., 1., 1.5, 0.};

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // perspective
    glFrustum(-20 * ((double)w/h) * (1. / sqrt(3)), 20 * ((double)w/h)* (1. / sqrt(3)), -20* (1. / sqrt(3)), 20* (1. / sqrt(3)), 20, 500.0);
}


// slots
void WorldWidget :: updateScene() {
    if (! paused) {
        time++;
        this -> repaint();
    }
}

void WorldWidget :: updateHorizontalView(int ang) {
    hViewAng = ang;
    cameraMovement = true;
    this -> repaint();
}

void WorldWidget :: updateVerticalView(int ang) {
    vViewAng = ang;
    cameraMovement = true;
    this -> repaint();
}

void WorldWidget :: updateZoom(int zoom) {
    this -> zoom = zoom;
    this -> zoom /= 10;
    cameraMovement = true;
    this -> repaint();
}

void WorldWidget :: changeTrajectory(int rad) {
    trajectoryRad = rad;
    trajectoryRad *= 10;
    manouvering = true;
    this -> repaint();
}

void WorldWidget :: changeAircraftSpeed(int speed) { aero -> changeAircraftSpeed(speed); }

void WorldWidget :: setCloudsAmount(int amount) { trail -> cloudsAmount = amount; }

void WorldWidget :: setCloudSpawnRate(int rate) { cloudSpawnRate = 16 - rate; }

void WorldWidget :: doAileronRoll() {
    if (!locked) locked = true;
    else return;
    rollAng = 360.;
    this -> repaint();
}

void WorldWidget :: changeAeroStyle(int selection) {
    aeroStyle = selection;
    this -> repaint();
}

void WorldWidget :: changeCloudStyle(int selection) {
    cloudStyle = selection;
    this -> repaint();
}

void WorldWidget :: shadeSmooth() {
    if (smooth) smooth = false;
    else smooth = true;
    this -> repaint();
}

void WorldWidget :: shutTurbo() {
    if (turboOff) turboOff = false;
    else turboOff = true;
}

void WorldWidget :: pause() {
    if (paused) paused = false;
    else paused = true;
}

void WorldWidget :: paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

    glLoadIdentity();

    glEnable(GL_MULTISAMPLE);

    // spherical coordinates of a point
    double px = cos(PI * (hViewAng) / 180);
    double py = sin(PI * (hViewAng) / 180);
    double pzc = cos(PI * (90 - vViewAng) / 180);
    double pzs = sin(PI * (90 - vViewAng) / 180);

    gluLookAt(140 * px * pzs, 140 * py * pzs,  140 * pzc,  0., 0., 0., 0., 0., 1.);

    glScalef((double)zoom * 0.2 + 1, (double)zoom * 0.2 + 1, (double)zoom * 0.2 + 1);


    // land
    glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT,    grassy.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    grassy.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   grassy.specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   grassy.shininess);

    gluDisk(gluNewQuadric(), 0., 40, 64, 64);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 0., -2.);

    glMaterialfv(GL_FRONT, GL_AMBIENT,    choco2.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    choco2.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   choco2.specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   choco2.shininess);

    glScalef(40., 40., 1.);
    gluCylinder(gluNewQuadric(), 1, 1, 2, 40, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0., 0., -2.);
    glRotatef(180, 0., 0., 1);
    gluDisk(gluNewQuadric(), 0., 40, 64, 64);
    glPopMatrix();


    // trees, stumps
    if (!smooth) glShadeModel(GL_FLAT);

    glPushMatrix();
    pine -> drawPines();
    glPopMatrix();


     // icosahedron and its stand
    glShadeModel(GL_SMOOTH);
    glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT,    base.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    base.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   base.specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   base.shininess);

    glTranslatef(29., -6., 0.);
    glScalef(2, 2, 2);
    gluCylinder(gluNewQuadric(), 1, 0.8, 1.5, 24, 12);
    glTranslatef(0., 0., 1.5);
    gluDisk(gluNewQuadric(), 0, 0.8, 24, 6);
    glTranslatef(0., 0., 2 + 0.5 * sin( (time % 360) / (180 / PI)));

    glPushMatrix();

    glRotatef(time * 0.5, 0, 1, 0);
    glRotatef(time * 0.5, 1, 0, 0);
    glRotatef(time * 0.5, 0, 0, 1);

    glShadeModel(GL_FLAT);
    shape2 -> icosahedron(&ico);
    glPopMatrix();

    glPopMatrix();


    // fence(s)
    glPushMatrix();
    glTranslatef(0., 5., 2.);
    fence -> drawFence(&choco);
    glPopMatrix();

    glShadeModel(GL_SMOOTH);

    // houses
    glPushMatrix();
    glTranslatef(12, 14, 0.3);
    glRotatef(180, 0., 0., 1.);
    house -> house(&houseWall);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.5, -21, 0.3);
    glRotatef(280, 0., 0., 1.);
    house -> house(&houseWall);
    glPopMatrix();

    // turbine
    glPushMatrix();
    glTranslatef(-4, 27.2, 0.);
    glRotatef(180, 0., 0., 1.);

    // the difference between paused and cameraMovement:
    // paused repaints the scene, but not any elements of animation (apart from camera controls), until the user unpauses.
    // cameraMovement refers to moments when user changes camera controls, such as zoom.
    // The widget is forced to update, but we dont want to repaint animations,
    // because it would look like the objects are moving in bursts.
    // therefore, when cameraMovement is on, we don't update animations for this paticular frame.
    // if cameraMovement is true, it is guaranteed to be false at the end of the frame.
    // cameraMovement acts as a one-time paused variable.

    if (cameraMovement) turbo -> turbo(turboOff, cameraMovement);
    else turbo -> turbo(turboOff, paused);
    glPopMatrix();

    double posX, posY;

    if (!paused && !manouvering && !cameraMovement) arcLen += aero -> speed;

    // compute aeroplane position. We make sure that the speed is not dependent on changes in trajectory radius (in else statement).
    if (!manouvering && !paused && !cameraMovement) {

        posX = trajectoryRad * sin(arcLen / (2 * PI * trajectoryRad));
        posY = trajectoryRad * cos(arcLen / (2 * PI * trajectoryRad));
        positionAng = arcLen / (2 * PI * trajectoryRad);

    // only when trajectory radius is changed.
    // We have to use the angular position instead of length, so the plane appears in the same position on the new circle.
    } else {

        posX = trajectoryRad * sin(positionAng);
        posY = trajectoryRad * cos(positionAng);
        arcLen = positionAng * (2 * PI * trajectoryRad);
        manouvering = false;
    }

    glPushMatrix();

    // set position on the circular path
    glTranslatef(posX, posY, 30);

    // rotate the airplane according to its position
    glRotatef( -(180 / PI) * (positionAng), 0.,0.,1.);

    // if doing roll
    if (locked) {
        rollAng--;
        glRotatef( rollAng, 1., 0., 0.);
        if (rollAng == 0) locked = false;
    }

    // Visual. The tilting that real airplanes make when they turn. Probably depends on speed too, but...
    glRotatef(5 + 550/trajectoryRad, 1., 0., 0.);

    // change airplane style / draw airplane
    if (!cameraMovement) {
        if (aeroStyle == 0) aero -> aeroplane(&redPlastic, 0, paused);
        else if (aeroStyle == 1) aero -> aeroplane(&silver, 1, paused);
        else aero -> aeroplane(&m200, 2, paused);
    } else {
        if (aeroStyle == 0) aero -> aeroplane(&redPlastic, 0, cameraMovement);
        else if (aeroStyle == 1) aero -> aeroplane(&silver, 1, cameraMovement);
        else aero -> aeroplane(&m200, 2, cameraMovement);
    }

    glPopMatrix();

    // culling
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // unit vectors to set direction of cloud movement
    double unitX = posX / sqrt(pow(posX, 2) + pow(posY, 2));
    double unitY = posY / sqrt(pow(posX, 2) + pow(posY, 2));

    // vertical vector is 0; aeroplane's path is horizontal
    double unitZ = 0;

    // stick an imaginary point to the plane's nose.
    // required to compute distance between clouds and the aeroplane to blow nearby clouds away
    trail -> afterEffect(trajectoryRad * sin((arcLen)/ (2 * PI * (trajectoryRad ))) + unitY * 20, trajectoryRad * cos((arcLen) / (2 * PI * (trajectoryRad ))) - unitX * 20, 30);

    // spawn a new cloud
    if (!cameraMovement && !paused && time % cloudSpawnRate == 0) trail -> spawn(posX, posY, 30., -unitY , unitX, unitZ, aero -> speed);

    // draw entire trail
    if (!cameraMovement) trail -> drawTrail(aero -> speed, this -> textures, paused, 3 - cloudStyle);
    else trail -> drawTrail(aero -> speed, this -> textures, cameraMovement, 3 - cloudStyle);

    glDisable(GL_CULL_FACE);

    // revert back to normal
    if (cameraMovement) cameraMovement = false;

    glLoadIdentity();

    // flush to screen
    glFlush();

    }
