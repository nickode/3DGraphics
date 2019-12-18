#pragma once

class Shader
{
private:
	unsigned int vertexshader;
	unsigned int fragmentshader;
	unsigned int program;

public:
	Shader(const char* vfile, const char* ffile);
	unsigned int getVertexShader();
	unsigned int getFragmentShader();
	unsigned int getProgram();
};