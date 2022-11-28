#ifndef __GL_POLYGON_WINDOW_H__
#define __GL_POLYGON_WINDOW_H__ 1

#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QBoxLayout>
#include <QObject>
#include <QTimer>
#include <QLabel>
#include <QGridLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QComboBox>

#include "WorldWidget.h"

class WorldWindow: public QWidget {

    Q_OBJECT

    public:
    WorldWindow(QWidget *parent);
    ~WorldWindow();

    // menu bar
    QMenuBar* menuBar;

    // file menu
    QMenu* fileMenu;

    // quit action
    QAction* actionQuit;

    // main layout
    QBoxLayout* boxLayout;
    // nested layout
    QGridLayout* gridLayout;

    // main widget
    WorldWidget* worldWidget;

    // sliders
    QSlider *vViewSlider, *hViewSlider, *zoomSlider,
        *trajectorySlider, *speedSlider, *cloudSlider, *cloudNumSlider;

    // labels
    QLabel *cameraLabel, *vViewLabel, *hViewLabel,
        *zoomLabel, *sceneControlLabel, *trajectoryLabel,
        * speedLabel, *pauseLabel, *rollLabel,
        *cloudLabel, *cloudNumLabel, *randomizedLabel, *smoothLabel,
        *turboLabel, *cloudStyleLabel, *aeroStyleLabel;

    // checkboxes
    QCheckBox *pauseCheckBox, *randomizedCheckBox, *smoothCheckBox, *turboCheckBox;

    // button
    QPushButton* rollButton;

    // combos
    QComboBox *aeroStyleCombo, *cloudStyleCombo;

    // timer for updating
    QTimer* tmr;

    void ResetInterface();
};

#endif

