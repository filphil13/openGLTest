#include "Cube.h"

Color polygonColor = {1.0f, 1.0f, 1.0f}; // Start with white color

void drawCube(unsigned int x, unsigned int y, unsigned int z, unsigned int scale )
{
    // CUBE FACE FRONT
    // CUBE FACE FRONT
    glBegin(GL_QUADS);      
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);
    glColor3f(0.0f, 1.0f, 0.0f); // Green  
    glVertex3f((0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f((0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);
    glEnd();

    // CUBE FACE BACK
    glBegin(GL_QUADS);        
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);        
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f((0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);        
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f((0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);        
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);    
    glEnd();

    // CUBE FACE TOP
    glBegin(GL_QUADS);        
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);        
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f((0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);        
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f((0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);        
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);    
    glEnd();

    // CUBE FACE BOTTOM
    glBegin(GL_QUADS);        
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);        
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f((0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);        
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f((0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);        
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);    
    glEnd();

    // CUBE FACE LEFT
    glBegin(GL_QUADS);        
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);        
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);        
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);        
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);    
    glEnd();

    // CUBE FACE RIGHT
    glBegin(GL_QUADS);        
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f( (0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);        
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f( (0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);        
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f( (0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);        
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f( (0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);    
    glEnd();
}