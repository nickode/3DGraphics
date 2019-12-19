#include <Data.h>

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VBO);
}

void VertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void VertexBuffer::bufferData(GLenum target, GLsizei size ,const float* vertices, GLenum usage)
{
	glBufferData(target, size, vertices, usage);
}

void VertexBuffer::deleteThis()
{
	glDeleteBuffers(1, &VBO);
}

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &VAO);
}

void VertexArray::bind()
{
	glBindVertexArray(VAO);
}

void VertexArray::unbind()
{
	glBindVertexArray(0);
}

void VertexArray::enable(int index, int size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(index);
}

void VertexArray::deleteThis()
{
	glDeleteVertexArrays(1, &VAO);
}

