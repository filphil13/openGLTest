#include "Keyboard.h"



Keyboard::Keyboard() {}

void Keyboard::keyboardCallback(Camera* camera, unsigned char key, int x, int y){
    printf("Key %c pressed at position (%d, %d)\n", key, x, y);
    
    if(key == 'w' || key == 'W'){
        camera->AddTranslation(0.0f, 0.0f, 0.1f);
    }
    if(key == 's' || key == 'S'){
        camera->AddTranslation(0.0f, 0.0f, -0.1f);
    }
    if(key == 'a' || key == 'A'){
        camera->AddTranslation(0.1f, 0.0f, 0.0f);
    }
    if(key == 'd' || key == 'D'){
        camera->AddTranslation(-0.1f, 0.0f, 0.0f);
    }
    if (key == ' '){
        camera->AddTranslation(0.0f, -0.1f, 0.0f);
    }
    
    // Example: Exit on 'q' key press
    if(key == 'q' || key == 'Q'){
        glutLeaveMainLoop();
    }
}