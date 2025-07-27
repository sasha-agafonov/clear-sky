#include "gui.hpp"

#include <QLineEdit>
#include <QListView>
#include <QSurfaceFormat>

#include "widgets/world_widget.hpp"

gui::gui(QWidget* parent) : QWidget(parent)
{

    menuBar = new QMenuBar(this);

    fileMenu = menuBar->addMenu("&Black Noise");

    actionQuit = new QAction("&Quit", this);

    fileMenu->addAction(actionQuit);

    boxLayout = new QBoxLayout(QBoxLayout :: LeftToRight, this);

    gridLayout = new QGridLayout();

    QSurfaceFormat fmt;
    fmt.setVersion(2, 1);
    fmt.setProfile(QSurfaceFormat::CompatibilityProfile);
    fmt.setDepthBufferSize(24);
    fmt.setSamples(4);
    world_widget_ = new world_widget(fmt, this);
    world_widget_->setMinimumSize(300, 300);
    world_widget_->setSizePolicy(QSizePolicy ::Expanding, QSizePolicy ::Expanding);


    vViewSlider = new QSlider(Qt :: Horizontal);
    vViewSlider -> setMaximum(89);
    vViewSlider -> setValue(40);
    vViewSlider -> setMinimum(0);
    vViewSlider -> setStyleSheet("QSlider { max-height: 24px; min-height: 24px; }"
                                 "QSlider::add-page:qlineargradient { background: rgba(110, 110, 135, 1); }"
                                 "QSlider::groove:horizontal { background: rgba(190, 190, 222, 1); height: 2px; }"
                                 "QSlider::handle:horizontal { background: rgba(190, 190, 222, 1); border: 2px solid rgba(1, 1, 1, 0); height: 10px; width: 10px; margin: -6 -1px; border-radius: 7px; }");

    hViewSlider = new QSlider(Qt :: Horizontal);
    hViewSlider -> setMaximum(360);
    hViewSlider -> setValue(260);
    hViewSlider -> setMinimum(0);
    hViewSlider -> setStyleSheet("QSlider { max-height: 24px; min-height: 24px; }"
                                 "QSlider::add-page:qlineargradient { background: rgba(110, 110, 135, 1); }"
                                 "QSlider::groove:horizontal { background: rgba(190, 190, 222, 1); height: 2px; }"
                                 "QSlider::handle:horizontal { background: rgba(190, 190, 222, 1); border: 2px solid rgba(1, 1, 1, 0); height: 10px; width: 10px; margin: -6 -1px; border-radius: 7px; }");

    zoomSlider = new QSlider(Qt :: Horizontal);
    zoomSlider -> setMaximum(100);
    zoomSlider -> setMinimum(1);
    zoomSlider -> setStyleSheet("QSlider { max-height: 24px; min-height: 24px; }"
                                "QSlider::add-page:qlineargradient { background: rgba(110, 110, 135, 1); }"
                                "QSlider::groove:horizontal { background: rgba(190, 190, 222, 1); height: 2px; }"
                                "QSlider::handle:horizontal { background: rgba(190, 190, 222, 1); border: 2px solid rgba(1, 1, 1, 0); height: 10px; width: 10px; margin: -6 -1px; border-radius: 7px; }");


    trajectorySlider = new QSlider(Qt :: Horizontal);
    trajectorySlider -> setMaximum(8);
    trajectorySlider -> setValue(4);
    trajectorySlider -> setMinimum(2);
    trajectorySlider -> setStyleSheet("QSlider { max-height: 24px; min-height: 24px; }"
                                "QSlider::add-page:qlineargradient { background: rgba(110, 110, 135, 1); }"
                                "QSlider::groove:horizontal { background: rgba(190, 190, 222, 1); height: 2px; }"
                                "QSlider::handle:horizontal { background: rgba(190, 190, 222, 1); border: 2px solid rgba(1, 1, 1, 0); height: 10px; width: 10px; margin: -6 -1px; border-radius: 7px; }");

    speedSlider = new QSlider(Qt :: Horizontal);
    speedSlider -> setMaximum(10);
    speedSlider -> setMinimum(2);
    speedSlider -> setStyleSheet("QSlider { max-height: 24px; min-height: 24px; }"
                                "QSlider::add-page:qlineargradient { background: rgba(110, 110, 135, 1); }"
                                "QSlider::groove:horizontal { background: rgba(190, 190, 222, 1); height: 2px; }"
                                "QSlider::handle:horizontal { background: rgba(190, 190, 222, 1); border: 2px solid rgba(1, 1, 1, 0); height: 10px; width: 10px; margin: -6 -1px; border-radius: 7px; }");

    cloudSlider = new QSlider(Qt :: Horizontal);
    cloudSlider -> setMaximum(100);
    cloudSlider -> setMinimum(10);
    cloudSlider -> setStyleSheet("QSlider { max-height: 24px; min-height: 24px; }"
                                "QSlider::add-page:qlineargradient { background: rgba(110, 110, 135, 1); }"
                                "QSlider::groove:horizontal { background: rgba(190, 190, 222, 1); height: 2px; }"
                                "QSlider::handle:horizontal { background: rgba(190, 190, 222, 1); border: 2px solid rgba(1, 1, 1, 0); height: 10px; width: 10px; margin: -6 -1px; border-radius: 7px; }");

    cloudNumSlider = new QSlider(Qt :: Horizontal);
    cloudNumSlider->setMaximum(15);
    cloudNumSlider -> setValue(15);
    cloudNumSlider -> setMinimum(1);
    cloudNumSlider -> setStyleSheet("QSlider { max-height: 24px; min-height: 24px; }"
                                "QSlider::add-page:qlineargradient { background: rgba(110, 110, 135, 1); }"
                                "QSlider::groove:horizontal { background: rgba(190, 190, 222, 1); height: 2px; }"
                                "QSlider::handle:horizontal { background: rgba(190, 190, 222, 1); border: 2px solid rgba(1, 1, 1, 0); height: 10px; width: 10px; margin: -6 -1px; border-radius: 7px; }");

    //checkboxes
    pauseCheckBox = new QCheckBox(this);
    pauseCheckBox -> setStyleSheet("QCheckBox::indicator { height: 10px; width: 10px; }"
                                   "QCheckBox::indicator:unchecked { border: 1px solid rgba(190, 190, 222, 1); background: transparent; border-radius: 5px;}"
                                   "QCheckBox::indicator:unchecked:hover { background: rgba(110, 110, 135, 1);  }"
                                   "QCheckBox::indicator:checked { border: 1px solid rgba(190, 190, 222, 1);  background: rgba(190, 190, 222, 1); border-radius: 5px; }"
                                   "QCheckBox::indicator:checked:hover { background: rgba(110, 110, 135, 1); border-color: rgba(110, 110, 135, 1); } ");

    randomizedCheckBox = new QCheckBox(this);
    randomizedCheckBox -> setChecked(true);
    randomizedCheckBox -> setStyleSheet("QCheckBox::indicator { height: 10px; width: 10px; }"
                                   "QCheckBox::indicator:unchecked { border: 1px solid rgba(190, 190, 222, 1); background: transparent; border-radius: 5px;}"
                                   "QCheckBox::indicator:unchecked:hover { background: rgba(110, 110, 135, 1);  }"
                                   "QCheckBox::indicator:checked { border: 1px solid rgba(190, 190, 222, 1);  background: rgba(190, 190, 222, 1); border-radius: 5px; }"
                                   "QCheckBox::indicator:checked:hover { background: rgba(110, 110, 135, 1); border-color: rgba(110, 110, 135, 1); } ");

    smoothCheckBox = new QCheckBox(this);
    smoothCheckBox -> setStyleSheet("QCheckBox::indicator { height: 10px; width: 10px; }"
                                   "QCheckBox::indicator:unchecked { border: 1px solid rgba(190, 190, 222, 1); background: transparent; border-radius: 5px;}"
                                   "QCheckBox::indicator:unchecked:hover { background: rgba(110, 110, 135, 1);  }"
                                   "QCheckBox::indicator:checked { border: 1px solid rgba(190, 190, 222, 1);  background: rgba(190, 190, 222, 1); border-radius: 5px; }"
                                   "QCheckBox::indicator:checked:hover { background: rgba(110, 110, 135, 1); border-color: rgba(110, 110, 135, 1); } ");

    turboCheckBox = new QCheckBox(this);
    turboCheckBox -> setStyleSheet("QCheckBox::indicator { height: 10px; width: 10px; }"
                                   "QCheckBox::indicator:unchecked { border: 1px solid rgba(190, 190, 222, 1); background: transparent; border-radius: 5px;}"
                                   "QCheckBox::indicator:unchecked:hover { background: rgba(110, 110, 135, 1);  }"
                                   "QCheckBox::indicator:checked { border: 1px solid rgba(190, 190, 222, 1);  background: rgba(190, 190, 222, 1); border-radius: 5px; }"
                                   "QCheckBox::indicator:checked:hover { background: rgba(110, 110, 135, 1); border-color: rgba(110, 110, 135, 1); } ");

    // button
    rollButton = new QPushButton("Press To Roll", this);
    rollButton -> setStyleSheet("QPushButton { height: 16px; min-height: 2em; background: rgba(190, 190, 222, 1); border: 0; font-size: 11px; color: rgba(40, 44, 52, 1); } "
                                "QPushButton:pressed { background: rgba(110, 110, 135, 1); } ");

    // combos
    aeroStyleCombo = new QComboBox(this);
    aeroStyleCombo -> addItems({ "Candy Apple", "Silver Pigeon", "M200"});
    aeroStyleCombo -> setEditable(true);
    aeroStyleCombo -> lineEdit() -> setReadOnly(true);
    aeroStyleCombo -> lineEdit() -> setAlignment(Qt::AlignCenter);
    aeroStyleCombo -> setView(new QListView());
    aeroStyleCombo -> setStyleSheet("QComboBox { border-radius: 0; min-height: 2em; border-width: 0px; background: rgba(190, 190, 222, 1); font-size: 11px; color: rgba(40, 44, 52, 1);}"
                                     "QComboBox:editable { background: rgba(190, 190, 222, 1); }"
                                     "QComboBox QAbstractItemView { background: rgba(40, 44, 52, 1); selection-color: black; color: rgba(190, 190, 222, 1); selection-background-color: rgba(110, 110, 135, 1); }"
                                     "QComboBox QAbstractItemView::item {min-height: 20px; font-size: 10px; }");

    aeroStyleCombo -> setItemData(0, Qt::AlignCenter, Qt::TextAlignmentRole);
    aeroStyleCombo -> setItemData(1, Qt::AlignCenter, Qt::TextAlignmentRole);
    aeroStyleCombo -> setItemData(2, Qt::AlignCenter, Qt::TextAlignmentRole);

    cloudStyleCombo = new QComboBox(this);
    cloudStyleCombo -> addItems({ "Classic White", "Planet Parade", "Many Marcs", "Many Markus's", "Disarray"});
    cloudStyleCombo -> setEditable(true);
    cloudStyleCombo -> lineEdit() -> setReadOnly(true);
    cloudStyleCombo -> lineEdit() -> setAlignment(Qt::AlignCenter);
    cloudStyleCombo -> setView(new QListView());
    cloudStyleCombo -> setStyleSheet("QComboBox { border-radius: 0; min-height: 2em; border-width: 0px; background: rgba(190, 190, 222, 1); font-size: 11px; color: rgba(40, 44, 52, 1); }"
                                     "QComboBox:editable { background: rgba(190, 190, 222, 1); }"
                                     "QComboBox QAbstractItemView { background: rgba(40, 44, 52, 1); selection-color: black; color: rgba(190, 190, 222, 1); selection-background-color: rgba(110, 110, 135, 1); }"
                                     "QComboBox QAbstractItemView::item {min-height: 20px; font-size: 10px; }");

    cloudStyleCombo -> setItemData(0, Qt::AlignCenter, Qt::TextAlignmentRole);
    cloudStyleCombo -> setItemData(1, Qt::AlignCenter, Qt::TextAlignmentRole);
    cloudStyleCombo -> setItemData(2, Qt::AlignCenter, Qt::TextAlignmentRole);
    cloudStyleCombo -> setItemData(3, Qt::AlignCenter, Qt::TextAlignmentRole);
    cloudStyleCombo -> setItemData(4, Qt::AlignCenter, Qt::TextAlignmentRole);

    // labels for each item
    cameraLabel = new QLabel(this);
    cameraLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    cameraLabel -> setText("Camera Controls");
    cameraLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); font-size: 10pt; }");

    vViewLabel = new QLabel(this);
    vViewLabel -> setText("Vertical View");
    vViewLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    hViewLabel = new QLabel(this);
    hViewLabel -> setText("Horizontal View");
    hViewLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    zoomLabel = new QLabel(this);
    zoomLabel -> setText("Zoom Level");
    zoomLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    sceneControlLabel = new QLabel(this);
    sceneControlLabel -> setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    sceneControlLabel -> setText("Scene Controls");
    sceneControlLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); font-size: 10pt; } ");

    trajectoryLabel = new QLabel(this);
    trajectoryLabel -> setText("Aircraft Trajectory");
    trajectoryLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    speedLabel = new QLabel(this);
    speedLabel -> setText("Aircraft Velocity");
    speedLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    aeroStyleLabel = new QLabel(this);
    aeroStyleLabel -> setText("Select Aircraft Style");
    aeroStyleLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    cloudStyleLabel = new QLabel(this);
    cloudStyleLabel -> setText("Select Contrail Style");
    cloudStyleLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    cloudNumLabel = new QLabel(this);
    cloudNumLabel -> setText("Contrail Intensity");
    cloudNumLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    cloudLabel = new QLabel(this);
    cloudLabel -> setText("Contrail Persistence");
    cloudLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    pauseLabel = new QLabel(this);
    pauseLabel -> setText("Pause Animation");
    pauseLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    randomizedLabel = new QLabel(this);
    randomizedLabel -> setText("Randomized Contrail");
    randomizedLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    rollLabel = new QLabel(this);
    rollLabel -> setText("Do Aileron Roll");
    rollLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    smoothLabel = new QLabel(this);
    smoothLabel -> setText("Shade Trees Smooth");
    smoothLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    turboLabel = new QLabel(this);
    turboLabel -> setText("Stop Wind Turbine");
    turboLabel -> setStyleSheet("QLabel { color: rgba(190, 190, 222, 1); margin-right: 6px; }");

    // ~ 60 fps
    tmr = new QTimer;
    tmr -> start(16);

    // connect all
    connect(vViewSlider, SIGNAL(valueChanged(int)), world_widget_, SLOT(updateVerticalView(int)));
    connect(hViewSlider, SIGNAL(valueChanged(int)), world_widget_, SLOT(updateHorizontalView(int)));
    connect(zoomSlider, SIGNAL(valueChanged(int)), world_widget_, SLOT(updateZoom(int)));
    connect(trajectorySlider, SIGNAL(valueChanged(int)), world_widget_, SLOT(changeTrajectory(int)));
    connect(cloudNumSlider, SIGNAL(valueChanged(int)), world_widget_, SLOT(setCloudSpawnRate(int)));
    connect(cloudSlider, SIGNAL(valueChanged(int)), world_widget_, SLOT(setCloudsAmount(int)));
    connect(speedSlider, SIGNAL(valueChanged(int)), world_widget_, SLOT(changeAircraftSpeed(int)));
    connect(cloudStyleCombo, SIGNAL(currentIndexChanged(int)), world_widget_, SLOT(changeCloudStyle(int)));
    connect(aeroStyleCombo, SIGNAL(currentIndexChanged(int)), world_widget_, SLOT(changeAeroStyle(int)));

    connect(pauseCheckBox, SIGNAL(stateChanged(int)), world_widget_, SLOT(pause()));
    connect(randomizedCheckBox, SIGNAL(stateChanged(int)), world_widget_ -> trail_, SLOT(randomizeTrail()));
    connect(smoothCheckBox, SIGNAL(stateChanged(int)), world_widget_, SLOT(shadeSmooth()));
    connect(turboCheckBox, SIGNAL(stateChanged(int)), world_widget_, SLOT(shutTurbo()));
    connect(rollButton, SIGNAL(clicked()), world_widget_, SLOT(doAileronRoll()));

    connect(tmr, SIGNAL(timeout()), world_widget_, SLOT(updateScene()));

    // add GL widget to main layout
    boxLayout->addWidget(world_widget_);

    // add other widgets to nested grid layouts
    gridLayout -> setColumnMinimumWidth(1, 110);

    gridLayout -> addWidget(cameraLabel, 0, 1, 1, 1);

    gridLayout -> addWidget(hViewLabel, 1, 0, 1, 1);
    gridLayout -> addWidget(hViewSlider, 1, 1, 1, 1);

    gridLayout -> addWidget(vViewLabel, 2, 0, 1, 1);
    gridLayout -> addWidget(vViewSlider, 2, 1, 1, 1);

    gridLayout -> addWidget(zoomLabel, 3, 0, 1, 1);
    gridLayout -> addWidget(zoomSlider, 3, 1, 1, 1);

    gridLayout -> addWidget(sceneControlLabel, 4, 1, 1, 1);

    gridLayout -> addWidget(trajectoryLabel, 5, 0, 1, 1);
    gridLayout -> addWidget(trajectorySlider, 5, 1, 1, 1);

    gridLayout -> addWidget(speedLabel, 6, 0, 1, 1);
    gridLayout -> addWidget(speedSlider, 6, 1, 1, 1);

    gridLayout -> addWidget(cloudNumLabel, 7, 0, 1, 1);
    gridLayout -> addWidget(cloudNumSlider, 7, 1, 1, 1);

    gridLayout -> addWidget(cloudLabel, 8, 0, 1, 1);
    gridLayout -> addWidget(cloudSlider, 8, 1, 1, 1);

    gridLayout -> addWidget(rollLabel, 9, 0, 1, 1);
    gridLayout -> addWidget(rollButton, 9, 1, 1, 1);

    gridLayout -> addWidget(aeroStyleLabel, 10, 0, 1, 1);
    gridLayout -> addWidget(aeroStyleCombo, 10, 1, 1, 1);

    gridLayout -> addWidget(cloudStyleLabel, 11, 0, 1, 1);
    gridLayout -> addWidget(cloudStyleCombo, 11, 1, 1, 1);

    gridLayout -> addWidget(randomizedLabel, 12, 0, 1, 1);
    gridLayout -> addWidget(randomizedCheckBox, 12, 1, 1, 1);

    gridLayout -> addWidget(smoothLabel, 13, 0, 1, 1);
    gridLayout -> addWidget(smoothCheckBox, 13, 1, 1, 1);

    gridLayout -> addWidget(turboLabel, 14, 0, 1, 1);
    gridLayout -> addWidget(turboCheckBox, 14, 1, 1, 1);

    gridLayout -> addWidget(pauseLabel, 15, 0, 1, 1);
    gridLayout -> addWidget(pauseCheckBox, 15, 1, 1, 1);

    // add grid layout to main layout
    boxLayout -> addLayout(gridLayout);

    // set ratio of main layout's items width
    boxLayout -> setStretchFactor(world_widget_, 80);
    boxLayout -> setStretchFactor(gridLayout, 20);

}

void gui::reset_interface()
{
    world_widget_->update();
    update();
}
