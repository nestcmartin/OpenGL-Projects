#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Input.h"
#include "Platform.h"

GLFWwindow* Input::window = nullptr;

double lastX = 0.0;
double lastY = 0.0;
double xoffset = 0.0;
double yoffset = 0.0;
double wheel = 0.0;

void Input::Init()
{
	int x, y;
	window = Platform::GetWindow();
	glfwGetFramebufferSize(window, &x, &y);
	lastX = x / 2.0f; lastY = y / 2.0f;

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Input::Release()
{ 
}

void Input::Update(float deltaTime)
{
	lastX = 0.0;
	lastY = 0.0;
	xoffset = 0.0;
	yoffset = 0.0;
	wheel = 0.0;
	glfwPollEvents();
}

bool Input::IsKeyDown(int key)
{
	return glfwGetKey(window, key) == GLFW_PRESS;
}

bool Input::IsKeyUp(int key)
{
	return glfwGetKey(window, key) == GLFW_RELEASE;
}

void Input::GetMousePosition(double& x, double& y)
{
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	x = xpos;
	y = ypos;
}