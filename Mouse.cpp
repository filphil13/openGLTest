#include "Mouse.h"

void mouseCallback(int button, int state, int x, int y){
    printf("Mouse button %d %s at position (%d, %d)\n", 
           button, 
           (state == GLUT_DOWN) ? "pressed" : "released", 
           x, y);
    }
}