#include <Setup.h>

class VertexBuffer
{
private:
	unsigned int VBO;
public:
	VertexBuffer();
	void bind();
	void bufferData(GLenum target, GLsizei size,const float* vertices, GLenum usage);
	void deleteThis();
};

class ElementBuffer
{
private:
	unsigned int EBO;
public:
	ElementBuffer();
	void bind();
	void bufferData();
	void deleteThis();
};

class VertexArray
{
private:
	unsigned int VAO;
public:
	VertexArray();
	void bind();
	void unbind();
	void enable(int index, int size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
	void deleteThis();
};

