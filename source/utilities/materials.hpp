#pragma once

#include <QtGui/qopengl.h> 

static const float PI = 3.1415926535;

struct material
{
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess;
};

static struct material whitesh = {
  { 1.0, 1.0, 1.0, 1.0},
  { 1.0, 1.0, 1.0, 1.0},
  { 1.0, 1.0, 1.0, 1.0},
  100.0
};

static struct material veryBadCloud {
    {2.0f,	2.0f,	2.0f,  1.f},
    {1.f,	1.f,	1.f,   1.f},
    {1.f,	1.0f,	1.0f,  1.f},
    5.f
};

static struct material redPlastic = {
    { 0.01,  0.01, 0.01, 1.f},
    { 0.4,	0.01,  0.01, 1.f},
    { 0.8,	0.6,   0.6,  1.f},
    32.f
};

static struct material badPlastic = {
    { 0.05f,	0.05f,	0.05f,  1.f },
    { 0.5f, 	0.5f,	0.5f,   1.f },
    { 0.7f,	    0.7f,	0.7f,   1.f },
    10.f
};

static struct material aeroWhite = {
    { 0.3f,	    0.3f,	0.3f,   1.f },
    { 0.9f, 	0.9f,	0.9f,   1.f },
    { 0.25f,    0.25f,	0.25f,  1.f },
    12.f
};

static struct material silver {
    {0.23f, 0.23f, 0.23f, 1.f},
    {0.28f, 0.28f, 0.28f, 1.f},
    {0.78, 0.78f, 0.78f, 1.f},
    51.f
};

static struct material m200 {
    { 0.04f, 0.1f,  0.04f, 1.f },
    { 0.30f, 0.35f, 0.37f, 1.f },
    { 0.02f, 0.1f,  0.02f, 1.f },
    2.f
};

static struct material choco {
    { 0.04f, 0.02f, 0.01f,   1.f },
    { 0.25f, 0.12f, 0.01f,   1.f },
    { 0.025f, 0.012f, 0.01f, 1.f },
    2.9f
};

static struct material choco2 {
    { 0.40, 0.40, 0.2f,  1.f },
    { 0.25, 0.12, 0.01f, 1.f },
    { 0.1, 0.05, 0.01f,  1.f },
    6.f
};

static struct material houseWall {
    { 1.9f, 1.7f, 1.7f,    1.f },
    { 0.25f, 0.25f, 0.25f, 1.f },
    { 0.1f, 0.1f, 0.1f,    1.f },
    10.f
};

static struct material houseWindow {
    { 0.1,  0.1,  0.1,  1.f},
    { 0.1,	0.1,  0.12, 1.f},
    { 0.9,	0.9,  0.9,  1.f},
    3.f
};

static struct material houseRoof {
    { 0.7f, 0.1f, 0.1f, 1.f },
    { 0.3f, 0.1f, 0.1f, 1.f },
    { 0.7f, 0.44f, 0.44f, 1.f },
    10.f
};

static struct material grassy {
    { 0.06f, 0.2f,  0.10f, 1.f },
    { 0.31f, 0.38f, 0.38f, 1.f },
    { 0.02f, 0.1f,  0.05f, 1.f },
    1.f
};

static struct material piny {
    { 0.1f, 0.24f,  0.21f,  1.f },
    { 0.28f, 0.44f, 0.42f,  1.f },
    { 0.03f, 0.05f,  0.05f, 1.f },
    2.f
};

static struct material ico {
    { 0.4f, 0.4f,  0.9f,  1.f },
    { 0.04f, 0.04f, 0.22f,  1.f },
    { 0.16f, 0.16f,  0.9f, 1.f },
    6.f
};

static struct material base {
    { 0.1f, 0.1f,  0.1f,  1.f },
    { 0.4f, 0.4f, 0.4f,  1.f },
    { 0.01f, 0.01f,  0.01f, 1.f },
    2.f
};
