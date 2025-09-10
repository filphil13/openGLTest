#include "Camera.h"

// Constructor - initializes all member variables
Camera::Camera() {
    rotationX = 0.0f;
    rotationY = 0.0f;
    rotationSpeedX = 0.0f;
    rotationSpeedY = 0.0f;
    translationSpeed = glm::vec3(0.0f, 0.0f, 0.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    position = glm::vec3(0.0f, 0.0f, 10.0f);
}

void Camera::CameraLoop() {
    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f); // Pitch
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f); // Yaw
    glRotatef(front.z, 0.0f, 0.0f, 1.0f); // Roll
    AddRotation(rotationSpeedX, rotationSpeedY);
    AddTranslation(translationSpeed.x, translationSpeed.y, translationSpeed.z);
}

void Camera::AddRotation(float deltaX, float deltaY) {
    printf("Camera rotation changed by (%f, %f)\n", deltaX, deltaY);
    rotationX += deltaX;
    rotationY += deltaY;
}

void Camera::AddTranslation(float deltaX, float deltaY, float deltaZ) {
    position += glm::vec3(deltaX, deltaY, deltaZ);
}

void Camera::MoveForward(float distance) {
    position.z += distance;
}

