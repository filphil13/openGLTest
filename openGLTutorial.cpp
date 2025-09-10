#include "openGLTutorial.h"
#include "Camera.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

// Define the polygon color variable

// Window and rotation variables
unsigned int windowWidth = 800;
unsigned int windowHeight = 600;

GLfloat mat_ambient[] = { 0.4, 0.2, 0.0, 1.0 };
GLfloat mat_specular[] = { 0.4, 0.4, 0.0, 1.0 };
GLfloat mat_diffuse[] = { 0.9, 0.5, 0.0, 1.0 };
GLfloat mat_shininess[] = { 0.0 };
GLfloat light_position0[] = { -5.0,5.0,5.0,1.0 };
GLfloat light_position1[] = { 5.0,5.0,5.0,1.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat model_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
// Create a global camera instance
Camera camera;


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
    glutSpecialFunc(specialKeyCallback);
    
    
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

        // Setup the material and lights used for our teapot
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

    glShadeModel(GL_SMOOTH);

    glEnable(GL_DEPTH_TEST);
    
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

    camera.CameraLoop();
    
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


    drawCube(0,0,0,2);



    glutSwapBuffers(); // swap front and back buffers for double buffering
    glutPostRedisplay(); // request a redraw for continuous animation
}

void mouseCallback(int button, int state, int x, int y){
    printf("Mouse button %d %s at position (%d, %d)\n", 
           button, 
           (state == GLUT_DOWN) ? "pressed" : "released", 
           x, y);
    
   
}

void keyboardCallback(unsigned char key, int x, int y){
    printf("Key %c pressed at position (%d, %d)\n", key, x, y);
    
    if(key == 'w' || key == 'W'){
        // Move the camera forward
        camera.AddTranslation(0.0f, 0.0f, 0.1f);
    }
    if(key == 's' || key == 'S'){
        // Move the camera backward
        camera.AddTranslation(0.0f, 0.0f, -0.1f);
    }
    if(key == 'a' || key == 'A'){
        // Move the camera left
        camera.AddTranslation(0.1f, 0.0f, 0.0f);
    }
    if(key == 'd' || key == 'D'){
        // Move the camera right
        camera.AddTranslation(-0.1f, 0.0f, 0.0f);
    }
    if(key == ' '){
        camera.AddTranslation(0.0f, -0.1f, 0.0f);
    }
    if(key == 'c' || key == 'C'){
        camera.AddTranslation(0.0f, 0.1f, 0.0f);
    }

    // Example: Exit on 'q' key press
    if(key == 'q' || key == 'Q'){
        glutLeaveMainLoop();
    }
}

void specialKeyCallback(int key, int x, int y) {
    printf("Key %c pressed at position (%d, %d)\n", key, x, y);

    switch (key) {
        case GLUT_KEY_UP:
            camera.AddRotation(-1.0f, 0.0f);
            break;
        case GLUT_KEY_DOWN:
            camera.AddRotation(1.0f, 0.0f);
            break;
        case GLUT_KEY_LEFT:
            camera.AddRotation(0.0f, -1.0f);
            break;
        case GLUT_KEY_RIGHT:
            camera.AddRotation(0.0f, 1.0f);
            break;
    }
}



