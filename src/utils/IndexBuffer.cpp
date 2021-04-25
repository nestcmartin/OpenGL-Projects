#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "IndexBuffer.h"

IndexBuffer::IndexBuffer() : count_(0)
{
	glGenBuffers(1, &EBO);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &EBO);
}

void IndexBuffer::load(const unsigned int* indices, unsigned int count)
{
	count_ = count;
	glBindBuffer(GL_ARRAY_BUFFER, EBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void IndexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, EBO);
}