#include "openGLTutorial.h"

// Define the polygon color variable

// Window and rotation variables
unsigned int windowWidth = 800;
unsigned int windowHeight = 600;

// Create a global camera instance
Camera* camera = new Camera();
Keyboard* keyboard = new Keyboard();
//Mouse* mouse = new Mouse();



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
    //glutMouseFunc(mouseCallback);
    glutKeyboardFunc(keyboardCallback);
    
    
    
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
    glutWarpPointer(windowWidth / 2, windowHeight / 2);
    
    // Reset modelview matrix for this frame
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    camera->CameraLoop();
    
    // Move the camera back to see the polygon
    glTranslatef(0.0f, 0.0f, -6.0f);

    // Set the polygon color using our color variable
    drawCube(0,0,0,2);

    glBegin(GL_QUADS);      
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(20.0f, 0.0f, 20.0f);
    glVertex3f(-20.0f, 0.0f, -20.0f);
    glVertex3f(20.0f, 0.0f, -20.0f);
    glVertex3f(-20.0f, 0.0f, 20.0f);
    glEnd();


    glutSwapBuffers(); // swap front and back buffers for double buffering
    glutPostRedisplay(); // Request a redraw for continuous animation
}


void keyboardCallback(unsigned char key, int x, int y) {
    keyboard->keyboardCallback(camera, key, x, y);
}
/*
void mouseCallback(int button, int state, int x, int y){
    mouse->mouseCallback(camera, button, state, x, y);
}
*/




