#ifndef TURBO_H
#define TURBO_H

#include "Materials.h"


class Turbo {

public:
    Turbo();
    void turbo( bool off, bool paused);
    bool off;
    int rAng;
};

#endif // TURBO_H
