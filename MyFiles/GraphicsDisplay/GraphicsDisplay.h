#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "info.h"
#include "window.h"


class GraphicsDisplay: public Observer<Info, State> {
    Xwindow xw;
    const int size;
    void drawCell(int r, int c, int colour);

public:
    GraphicsDisplay(int n);
    void notify(Subject<Info, State> &whoNotified) override;

};

#endif

