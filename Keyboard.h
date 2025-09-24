#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "Camera.h"
#include <cstdio>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>


class Keyboard {
public:
    Keyboard();
    void keyboardCallback(Camera* camera, unsigned char key, int x, int y);
    
private:
    
};

#endif // KEYBOARD_H