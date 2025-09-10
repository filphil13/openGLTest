#include <GL/gl.h>
struct Color {
    float r, g, b;
};

Color polygonColor = {1.0 , 1.0 , 1.0 }; // Start with white color

void drawCube(unsigned int x, unsigned int y, unsigned int z, unsigned int scale )
{
    // CUBE FACE FRONT
    glBegin(GL_QUADS);      
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);
    glColor3f(0.0f, 1.0f, 0.0f); // Green  
    glVertex3f((0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);
    glColor3f(0.0f, 1.0f, 0.0f); // Green (or another color)
    glVertex3f((0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);
    glEnd();
    
    // CUBE FACE BACK
    glColor3f(polygonColor.r, polygonColor.g, polygonColor.b);
    glBegin(GL_QUADS);        
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);        
    glVertex3f((0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);        
    glVertex3f((0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);        
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);    
    glEnd();

    // CUBE FACE TOP
    glColor3f(polygonColor.r, polygonColor.g, polygonColor.b);
    glBegin(GL_QUADS);        
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);        
    glVertex3f((0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);        
    glVertex3f((0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);        
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);    
    glEnd();

    // CUBE FACE BOTTOM
    glColor3f(polygonColor.r, polygonColor.g, polygonColor.b);
    glBegin(GL_QUADS);        
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);        
    glVertex3f((0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);        
    glVertex3f((0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);        
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);    
    glEnd();

    // CUBE FACE LEFT
    glColor3f(polygonColor.r, polygonColor.g, polygonColor.b);
    glBegin(GL_QUADS);        
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);        
    glVertex3f((-0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);        
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);        
    glVertex3f((-0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);    
    glEnd();

    // CUBE FACE RIGHT
    glColor3f(polygonColor.r, polygonColor.g, polygonColor.b);
    glBegin(GL_QUADS);        
    glVertex3f( (0.5 + x) * scale, (-0.5 + y) * scale, (0.5 + z) * scale);        
    glVertex3f( (0.5 + x) * scale, (-0.5 + y) * scale, (-0.5 + z) * scale);        
    glVertex3f( (0.5 + x) * scale, (0.5 + y) * scale, (-0.5 + z) * scale);        
    glVertex3f( (0.5 + x) * scale, (0.5 + y) * scale, (0.5 + z) * scale);    
    glEnd();
}