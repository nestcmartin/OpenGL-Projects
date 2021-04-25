#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexArray.h"
#include "VertexBuffer.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &VAO);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &VAO);
}

void VertexArray::bind() const
{
	glBindVertexArray(VAO);
}