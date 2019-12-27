#pragma once
#include <openglstarterpack.h>

class Buffer
{
private:
	unsigned int id;
public:
	void bind() {};
	virtual void bufferData(GLenum target, GLsizei size, const float* vertices, GLenum usage) {};
	virtual void deleteThis() {};
};

class VertexBuffer: public Buffer
{
private:
	unsigned int id;
public:
	VertexBuffer();
	void bind();
	void bufferData(GLenum target, GLsizei size, glm::vec3* vertices, GLenum usage);
	void deleteThis();
};


class ElementBuffer: public Buffer
{
private:
	unsigned int id;
public:
	ElementBuffer();
	void bind();
	void bufferData(GLenum target, GLsizei size, const unsigned int* indices, GLenum usage);
	void deleteThis();
};

class VertexArray
{
private:
	unsigned int id;
public:
	VertexArray();
	void bind();
	void unbind();
	void enable(int index, int size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
	void deleteThis();
};

