#include "openGLTutorial.h"



// Define the polygon color variable

// Window and rotation variables
unsigned int windowWidth = 800;
unsigned int windowHeight = 600;

// Menu variable
int menu_id;

// Menu callback function
void mymenu(int value) {
    switch(value) {
        case 1: // Clear Screen
            polygonColor.r = 0.0f;
            polygonColor.g = 0.0f; 
            polygonColor.b = 0.0f;
            printf("Screen cleared (background color)\n");
            glutPostRedisplay();
            break;
        case 2: // Exit
            printf("Exiting from menu...\n");
            glutLeaveMainLoop();
            break;
        default:
            break;
    }
}

int main(int argc, char** argv){
    printf("Hello OpenGL\n");

    glutInit(&argc, argv);
    initGLUT();

    // Initialize GLEW after creating OpenGL context
    GLenum glewError = glewInit();
    if(glewError != GLEW_OK){
        printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
        return 1;
    }

    glutDisplayFunc(display);
    glutMouseFunc(mouseCallback);
    glutKeyboardFunc(keyboardCallback);
    
    // Create menu (corrected syntax)
    menu_id = glutCreateMenu(mymenu);
    glutAddMenuEntry("Clear Screen", 1);
    glutAddMenuEntry("Exit", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    initGL(windowWidth, windowHeight);
    glutMainLoop();

    return 0;
}
void initGL(unsigned int w, unsigned int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    gluPerspective(60.0,(double)w/(double)h,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set clear color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0 );
}

void initGLUT(){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OpenGL Tutorial");

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // reset background

    
    // Reset modelview matrix for this frame
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Camera();
    
    // Move the camera back to see the polygon
    glTranslatef(0.0f, 0.0f, -6.0f);

    // Set the polygon color using our color variable
    drawCube(0,0,0,2);


    glutSwapBuffers(); // swap front and back buffers for double buffering
    glutPostRedisplay(); // Request a redraw for continuous animation
}


void mouseCallback(int button, int state, int x, int y){
    printf("Mouse button %d %s at position (%d, %d)\n", 
           button, 
           (state == GLUT_DOWN) ? "pressed" : "released", 
           x, y);
    
    // Example: Change polygon color on left click
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        // Set polygon color to a random color on left mouse click
        polygonColor.r = static_cast<float>(rand()) / RAND_MAX;
        polygonColor.g = static_cast<float>(rand()) / RAND_MAX;
        polygonColor.b = static_cast<float>(rand()) / RAND_MAX;
        // Force a redraw
        glutPostRedisplay();
    }
}

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
    if(key == 'w' || key == 'W'){
        // Move the camera forward
        AddTranslation(0.0f, 0.0f, 0.1f);
    }
    if(key == 's' || key == 'S'){
        // Move the camera backward
        AddTranslation(0.0f, 0.0f, -0.1f);
    }
    if(key == 'a' || key == 'A'){
        // Move the camera left
        AddTranslation(-0.1f, 0.0f, 0.0f);
    }
    if(key == 'd' || key == 'D'){
        // Move the camera right
        AddTranslation(0.1f, 0.0f, 0.0f);
    }
    if(key == 'r' || key == 'R'){
        // Move the camera up
        AddTranslation(0.0f, 0.1f, 0.0f);
    }
    if(key == 'f' || key == 'F'){
        // Move the camera down
        AddTranslation(0.0f, -0.1f, 0.0f);
    }
    
    // Example: Exit on 'q' key press
    if(key == 'q' || key == 'Q'){
        glutLeaveMainLoop();
    }
}



