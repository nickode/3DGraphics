#pragma once
#include <Setup.h>

class VertexBuffer
{
private:
	unsigned int VBO;
public:
	VertexBuffer();
	void bind();
	void bufferData(float* vertices, GLenum usage);
};

class VertexArray
{
private:
	unsigned int VAO;
public:
	VertexArray();
	void bind();
};