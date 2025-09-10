#ifndef CAMERA_H
#define CAMERA_H
#include <GL/gl.h>
#include <glm/glm.hpp>

class Camera {
public:
    // Member variables
    float rotationX;
    float rotationY;
    float rotationSpeedX;
    float rotationSpeedY;
    glm::vec3 translationSpeed;
    glm::vec3 front;
    glm::vec3 position;
    glm::vec3 up;

    // Constructor
    Camera();

    // Member functions
    void AddRotation(float deltaX, float deltaY);
    void AddTranslation(float deltaX, float deltaY, float deltaZ);
    void MoveForward(float distance);
    void MoveBackward(float distance);
    void MoveLeft(float distance);
    void MoveRight(float distance);
    void MoveUp(float distance);
    void MoveDown(float distance);
    
    void CameraLoop();
};

#endif
