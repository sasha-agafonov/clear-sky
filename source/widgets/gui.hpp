#pragma once

#include <QMenuBar>
#include <QSlider>
#include <QBoxLayout>
#include <QTimer>
#include <QLabel>
#include <QGridLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QComboBox>

class world_widget;

class gui: public QWidget
{
    Q_OBJECT

public:

    explicit gui(QWidget* parent = nullptr);

private:

    QAction* actionQuit = nullptr;

    QBoxLayout* boxLayout = nullptr;

    QCheckBox* pauseCheckBox = nullptr;
    QCheckBox* randomizedCheckBox = nullptr;
    QCheckBox* smoothCheckBox = nullptr;
    QCheckBox* turboCheckBox = nullptr;

    QComboBox* aeroStyleCombo = nullptr;
    QComboBox* cloudStyleCombo = nullptr;

    QGridLayout* gridLayout = nullptr;

    QLabel* cameraLabel = nullptr;
    QLabel* vViewLabel = nullptr;
    QLabel* hViewLabel = nullptr;
    QLabel* zoomLabel = nullptr;
    QLabel* sceneControlLabel = nullptr;
    QLabel* trajectoryLabel = nullptr;
    QLabel* speedLabel = nullptr;
    QLabel* pauseLabel = nullptr;
    QLabel* rollLabel = nullptr;
    QLabel* cloudLabel = nullptr;
    QLabel* cloudNumLabel = nullptr;
    QLabel* randomizedLabel = nullptr;
    QLabel* smoothLabel = nullptr;
    QLabel* turboLabel = nullptr;
    QLabel* cloudStyleLabel = nullptr;
    QLabel* aeroStyleLabel = nullptr;

    QMenu* fileMenu = nullptr;

    QMenuBar* menuBar = nullptr;

    QPushButton* rollButton = nullptr;

    QSlider* vViewSlider = nullptr;
    QSlider* hViewSlider = nullptr;
    QSlider* zoomSlider = nullptr;
    QSlider* trajectorySlider = nullptr;
    QSlider* speedSlider = nullptr;
    QSlider* cloudSlider = nullptr;
    QSlider* cloudNumSlider = nullptr;

    QTimer* tmr = nullptr;

    world_widget* world_widget_ = nullptr;

    void reset_interface();
};
