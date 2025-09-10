cmake_minimum_required(VERSION 3.10)
project(openGLTutorial)

set(CMAKE_CXX_STANDARD 11)

add_executable(openGLTutorial openGLTutorial.cpp)

# Find OpenGL
cmake_policy(SET CMP0072 NEW)
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

# If you use GLU, GLUT, GLFW, or GLEW, you can add them here
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
# find_package(GLFW REQUIRED)

# Link OpenGL libraries
if(OpenGL_FOUND AND GLUT_FOUND AND GLEW_FOUND)
    target_link_libraries(openGLTutorial PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT GLEW::GLEW)
endif()
