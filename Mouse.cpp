
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