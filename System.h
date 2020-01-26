#pragma once
#include <openglstarterpack.h>
#include <Camera.h>
#include <filesystem>
#include <iostream>

class System
{

public:
	//Window context
	GLFWwindow* window;
	Camera* c;

	//System Paths
	const char* gModelsPath = "./models"; //models path
	const char* gTexturesPath = "./textures"; //textures path
	const char* gShadersPath = "./shaders"; //other file paths (temp)

	//Time variables
	double currentTime;
	double lastTime;
	double deltaTime;

	//View

public:
	System(unsigned int width, unsigned int height);

};

extern System* sys;

void init();
void mouse_callback_fpv(GLFWwindow* window, double xpos, double ypos);
void processInput();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);



