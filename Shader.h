#pragma once
#ifndef SHADER
#define SHADER

#include <openglstarterpack.h>
#include <iostream>
#include <fstream>
#include <streambuf>

class Shader
{
private:
	unsigned int vertexshader;
	unsigned int fragmentshader;
	unsigned int program;
public:
	Shader(const char* vfile, const char* ffile);
	unsigned int getProgram();
	void use();

	void setVec3(const char* name, glm::vec3 vec);
	void setFloat(const char* name, float f);
};

#endif