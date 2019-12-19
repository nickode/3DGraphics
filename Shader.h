#pragma once
#include <Setup.h>
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
};