#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "Platform.h"
#include "Renderer.h"
#include "FileSystem.h"
#include "Shader.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);

GLFWwindow* Renderer::window = nullptr;

// Viewport Attributes
int Renderer::ViewportX = 0;
int Renderer::ViewportY = 0;
int Renderer::ViewportWidth = 0;
int Renderer::ViewportHeight = 0;

void Renderer::Init()
{
	window = Platform::GetWindow();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwGetFramebufferSize(window, &ViewportWidth, &ViewportHeight);
	glViewport(0, 0, ViewportWidth, ViewportHeight);

	glEnable(GL_DEPTH_TEST);

	// System specific data
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum number of vertex attributes supported: " << nrAttributes << std::endl;
}

void Renderer::Release()
{
	Present();
}

void Renderer::Clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(unsigned int vao, unsigned int count, unsigned int shader)
{
	glUseProgram(shader);
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
}

void Renderer::Present()
{
	glfwSwapBuffers(window);
}

void Renderer::EnableWireframeMode()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Renderer::DisableWireframeMode()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

RenderData* Renderer::GetRenderData(
	const float* vertices, unsigned int verts, 
	const unsigned int* layout, unsigned int attrs, 
	const unsigned int* indices, unsigned int elems, 
	const char* shader)
{
	unsigned int stride = 0;
	for (size_t i = 0; i < attrs; i++)
	{
		stride += layout[i] * sizeof(float);
	}

	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, stride * verts, vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, elems * sizeof(indices), indices, GL_STATIC_DRAW);

	unsigned int offset = 0;
	for (size_t i = 0; i < attrs; i++)
	{
		glVertexAttribPointer(i, layout[i], GL_FLOAT, GL_FALSE, stride, (void*)offset);
		glEnableVertexAttribArray(i);
		offset += layout[i] * sizeof(float);
	}

	return new RenderData({ VAO, elems, FileSystem::GetShader(shader) });
}

void Renderer::UpdateViewport(int x, int y, int w, int h)
{
	ViewportX = x;
	ViewportY = y;
	ViewportWidth = w;
	ViewportHeight = h;
	glViewport(x, y, w, h);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	Renderer::UpdateViewport(0, 0, width, height);
}