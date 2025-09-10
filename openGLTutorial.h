
#ifndef OPENGLTUTORIAL_H
#define OPENGLTUTORIAL_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
using namespace glm;
using namespace std;

struct Color {
    float r, g, b;
};

struct Cube {
    float size;
    Color color;
};

extern Color polygonColor;

extern unsigned int windowWidth;
extern unsigned int windowHeight;
extern float rotationX;
extern float rotationY;

extern string windowTitle;
extern int menu_id;

// Function declarations
void mymenu(int value);

void display();
void initGL(unsigned int w=windowWidth, unsigned int h=windowHeight);
void mouseCallback(int button, int state, int x, int y);
void keyboardCallback(unsigned char key, int x, int y);
void drawCube(unsigned int x, unsigned int y, unsigned int z, unsigned int scale );
void Camera();

#endif // OPENGLTUTORIAL_H