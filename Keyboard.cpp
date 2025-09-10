#include <cstdio>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>

void keyboardCallback(unsigned char key, int x, int y){
    printf("Key %c pressed at position (%d, %d)\n", key, x, y);
    // Example: Change polygon color on 'c' key press
    if(key == 'c' || key == 'C'){
        // Cycle through different colors
        static int colorIndex = 0;
        switch(colorIndex % 4){
            case 0: // Red
                polygonColor.r = 1.0 ; polygonColor.g = 0.0f; polygonColor.b = 0.0f;
                break;
            case 1: // Green
                polygonColor.r = 0.0f; polygonColor.g = 1.0 ; polygonColor.b = 0.0f;
                break;
            case 2: // Blue
                polygonColor.r = 0.0f; polygonColor.g = 0.0f; polygonColor.b = 1.0 ;
                break;
            case 3: // White
                polygonColor.r = 1.0 ; polygonColor.g = 1.0; polygonColor.b = 1.0 ;
                break;
        }
        colorIndex++;
        printf("Changed polygon color to %s\n", 
               (colorIndex-1) % 4 == 0 ? "Red" :
               (colorIndex-1) % 4 == 1 ? "Green" :
               (colorIndex-1) % 4 == 2 ? "Blue" : "White");
        // Force a redraw
        glutPostRedisplay();
    }
    // Example: Exit on 'q' key press
    if(key == 'q' || key == 'Q'){
        glutLeaveMainLoop();
    }
}