QT       += \
    core gui \
    core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 \
    warn_off

# LIBS += -lGLU
LIBS += -lopengl32 -lglu32

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Aero.cpp \
    Cloud.cpp \
    CloudTrail.cpp \
    Fence.cpp \
    House.cpp \
    Pine.cpp \
    Shape.cpp \
    Turbo.cpp \
    WorldMain.cpp \
    WorldWidget.cpp \
    WorldWindow.cpp

HEADERS += \
    Aero.h \
    Cloud.h \
    CloudTrail.h \
    Fence.h \
    House.h \
    Materials.h \
    Pine.h \
    Shape.h \
    Turbo.h \
    WorldWidget.h \
    WorldWindow.h

FORMS += \
    WorldWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
