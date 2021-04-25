#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Platform.h"

GLFWwindow* Platform::Window = nullptr;

void Platform::Init()
{
	// GLFW Init
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (!Window)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(Window);

	// GLAD Init
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
	}
}

void Platform::Release()
{
	glfwTerminate();
}

void Platform::SetWindowShouldClose(bool close)
{
	glfwSetWindowShouldClose(Window, close);
}

bool Platform::GetWindowShouldClose()
{
	return glfwWindowShouldClose(Window);
}

float Platform::GetTime()
{
	return static_cast<float>(glfwGetTime());
}
