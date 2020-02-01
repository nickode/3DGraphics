#pragma once
#include <Camera.h>
#include <Scene.h>

//Components
extern GLFWwindow* window;
extern Camera* c;
extern Scene* s;

//System Variables
extern double currentTime;
extern double lastTime;
extern float deltaTime;
extern unsigned int width;
extern unsigned int height;

//Shader ids
extern GLint iView;

void StartupRenderEngine();
void mouse_callback_fpv(GLFWwindow* window, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput();

