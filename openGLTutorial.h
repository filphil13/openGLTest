
#ifndef OPENGLTUTORIAL_H
#define OPENGLTUTORIAL_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Cube.h"
#include "Camera.h"
#include "Keyboard.h"
//#include "Mouse.h"

using namespace glm;
using namespace std;




extern unsigned int windowWidth;
extern unsigned int windowHeight;
extern float rotationX;
extern float rotationY;

extern string windowTitle;

void display();
void initGL(unsigned int w=windowWidth, unsigned int h=windowHeight);
void mouseCallback(int button, int state, int x, int y);
void keyboardCallback(unsigned char key, int x, int y);
void initGLUT();

#endif // OPENGLTUTORIAL_H