#ifndef CUBE_H
#define CUBE_H

#include <GL/gl.h>
struct Color {
    float r, g, b;
};


extern Color polygonColor;
void drawCube(unsigned int x, unsigned int y, unsigned int z, unsigned int scale=1);
#endif // CUBE_H