#ifndef SETUP
#define SETUP

#include <openglstarterpack.h>
#include <iostream>

//GLFW Context
extern GLFWwindow* window;

//System Variables
extern double currentTime;
extern double lastTime;
extern float deltaTime;
extern int8_t fpsFlag;
extern int8_t inputFlag;
extern int8_t stopFps;
extern int8_t stopInput;

void processInput();
void countFps();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* initOpenGL(unsigned int width, unsigned int height);

#endif
