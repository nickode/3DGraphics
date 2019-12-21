#include <Storage.h>

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &id);
}

void VertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::bufferData(GLenum target, GLsizei size ,const float* vertices, GLenum usage)
{
	glBufferData(target, size, vertices, usage);
}

void VertexBuffer::deleteThis()
{
	glDeleteBuffers(1, &id);
}

ElementBuffer::ElementBuffer()
{
	glGenBuffers(1, &id);
}

void ElementBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void ElementBuffer::bufferData(GLenum target, GLsizei size, const unsigned int* indices, GLenum usage)
{
	glBufferData(target, size, indices, usage);
}

void ElementBuffer::deleteThis()
{
	glDeleteBuffers(1, &id);
}

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &id);
}

void VertexArray::bind()
{
	glBindVertexArray(id);
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
	glDeleteVertexArrays(1, &id);
}

