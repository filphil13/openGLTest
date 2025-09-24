#ifndef MOUSE_H
#define MOUSE_H

#include <GL/freeglut_std.h>
#include <cstdio>
#include "Camera.h"

class Mouse {
public:
    Mouse();
    void mouseCallback(Camera camera, int button, int state, int x, int y);

private:
    float m_x, m_y;
    bool m_buttons[8]; // Support for multiple mouse buttons
    float m_scrollX, m_scrollY;
};

#endif // MOUSE_H