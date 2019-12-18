#include <Data.h>

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VBO);
}

void VertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void VertexBuffer::bufferData(float* vertices, GLenum usage)
{
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, usage);
}

VertexArray::VertexArray()
{
	
}