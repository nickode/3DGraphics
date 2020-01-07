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
	GLint id;

public:
	Shader(const char* vfile, const char* ffile);
	unsigned int getProgram();
	void use();
	GLint getId();
};

#endif