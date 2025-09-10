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
    up = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Camera::CameraLoop() {
    gluLookAt(position.x, position.y, position.z, position.x + front.x, position.y + front.y, position.z + front.z, up.x, up.y, up.z);

}

void Camera::AddRotation(float deltaX, float deltaY) {
    printf("Camera rotation changed by (deltaX: %f, deltaY: %f)\n", deltaX, deltaY);
    rotationX += deltaX;
    rotationY += deltaY;
    printf("New rotationX: %f, rotationY: %f\n", rotationX, rotationY);
    front.x = cos(glm::radians(rotationY)) * cos(glm::radians(rotationX));
    front.y = sin(glm::radians(rotationX));
    front.z = sin(glm::radians(rotationY)) * cos(glm::radians(rotationX));
    front = glm::normalize(front);
    printf("Front vector after rotation: x=%f, y=%f, z=%f\n", front.x, front.y, front.z);
    printf("Camera position: x=%f, y=%f, z=%f\n", position.x, position.y, position.z);
}


void Camera::MoveForward(float distance) {
    position += front * distance;
}

void Camera::MoveBackward(float distance) {
    position -= front * distance;
}

void Camera::MoveLeft(float distance) {
    position -= glm::normalize(glm::cross(front, up)) * distance;
}

void Camera::MoveRight(float distance) {
    position += glm::normalize(glm::cross(front, up)) * distance;
}

void Camera::MoveUp(float distance) {
    position += up * distance;
}

void Camera::MoveDown(float distance) {
    position -= up * distance;
}
