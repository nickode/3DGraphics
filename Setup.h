#pragma once
#ifndef SETUP
#define SETUP

#include <openglstarterpack.h>
#include <Storage.h>
#include <Shader.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
GLFWwindow* initOpenGL();

#endif


