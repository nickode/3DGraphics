#ifndef SETUP
#define SETUP

#include <openglstarterpack.h>
#include <iostream>
#include <Camera.h>

//GLFW Context
extern GLFWwindow* window;
extern Camera* c;

//projection
extern glm::mat4 projection;
extern float fov;

//System Variables
extern double currentTime;
extern double lastTime;
extern float deltaTime;
extern int8_t fpsFlag;
extern int8_t inputFlag;
extern int8_t stopFps;
extern int8_t stopInput;

void countFps();
GLFWwindow* init(unsigned int width, unsigned int height);
void fps_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void godmode_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback_fpv(GLFWwindow* window, double xpos, double ypos);

void processInput();




#endif
