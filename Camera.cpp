#include <GL/gl.h>
#include <glm/glm.hpp>
using namespace glm;

float rotationSpeedX = 0.0f; // Rotation speed around X-axis
float rotationSpeedY = 0.0f; // Rotation speed around Y-axis

vec3 translationSpeed = vec3(0.0f, 0.0f, 0.0f);

vec3 front = vec3(0.0f, 0.0f, -1.0f); // Forward direction

vec3 position = vec3(0.0f, 0.0f, -6.0f);


void AddRotation(float deltaX, float deltaY) {
    rotationX += deltaX;
    rotationY += deltaY;
}

void AddTranslation(float deltaX, float deltaY, float deltaZ) {
    position += vec3(deltaX, deltaY, deltaZ);
}

void MoveForward(float distance) {
    translationZ += distance;
}

void Camera() {
    glTranslatef(position.x, position.y, position.z);
    glRotatef(front.x, 1.0f, 0.0f, 0.0f); // Pitch
    glRotatef(front.y, 0.0f, 1.0f, 0.0f); // Yaw
    glRotatef(front.z, 0.0f, 0.0f, 1.0f); // Roll
    AddRotation(rotationSpeedX, rotationSpeedY); // Different speeds for X and Y create interesting motion
}

