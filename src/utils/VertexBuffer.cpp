#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &VBO);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &VBO);
}

void VertexBuffer::load(const float* vertices)
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}