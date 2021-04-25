#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.h"
#include "Input.h"
#include "Platform.h"
#include "Renderer.h"

float lastX = 0.0f;
float lastY = 0.0f;
bool firstMouse = true;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// Camera Vectors
glm::vec3 Camera::WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 Camera::Position = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 Camera::Front = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 Camera::Up = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 Camera::Right = glm::vec3(1.0f, 0.0f, 0.0f);;

// Euler Angles
float Camera::Yaw = -90.0f;
float Camera::Pitch = 0.0f;
float Camera::Roll = 0.0f;

// Frustum
float Camera::Fovy = 45.0f;
float Camera::AspectRatio = 0.0f;
float Camera::Near = 0.1f;
float Camera::Far = 100.0f;
bool Camera::Ortographic = false;

// Camera Controller
float Camera::MovementSpeed = 2.5f;
float Camera::MouseSensitivity = 0.1f;

void Camera::Init(glm::vec3 pos, glm::vec3 up, float yaw, float pitch)
{
	lastX = (float)Renderer::GetViewportWidth() / 2.0f;
	lastY = (float)Renderer::GetViewportHeight() / 2.0f;

	AspectRatio = (float)Renderer::GetViewportWidth() / (float)Renderer::GetViewportHeight();
	Position = pos;
	Up = up;
	Yaw = yaw;
	Pitch = pitch;

	InternalUpdate();

	GLFWwindow* window = Platform::GetWindow();
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
}

void Camera::Release()
{
}

glm::mat4 Camera::ViewMatrix()
{	
	return glm::lookAt(Position, Position + Front, Up);
}

glm::mat4 Camera::ProjectionMatrix()
{
	//if (!ortographic_)
	return glm::perspective(glm::radians(Fovy), AspectRatio, Near, Far);
}

void Camera::Update(float deltaTime)
{
	if (Input::IsKeyDown(GLFW_KEY_W))
		Position += MovementSpeed * deltaTime * Front;
	if (Input::IsKeyDown(GLFW_KEY_S))
		Position -= MovementSpeed * deltaTime * Front;
	if (Input::IsKeyDown(GLFW_KEY_A))
		Position -= glm::normalize(glm::cross(Front, Up)) * MovementSpeed * deltaTime;
	if (Input::IsKeyDown(GLFW_KEY_D))
		Position += glm::normalize(glm::cross(Front, Up)) * MovementSpeed * deltaTime;

	// FPS Camera hack
	//Position.y = 0.0f;
}

void Camera::InternalUpdate()
{
	glm::vec3 front;
	front.x = glm::cos(glm::radians(Yaw)) * glm::cos(glm::radians(Pitch));
	front.y = glm::sin(glm::radians(Pitch));
	front.z = glm::sin(glm::radians(Yaw)) * glm::cos(glm::radians(Pitch));
	Front = glm::normalize(front);	
	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset)
{
	xoffset *= MouseSensitivity;
	yoffset *= MouseSensitivity;
	Yaw += xoffset;
	Pitch += yoffset;
	if (Pitch > 89.0f) Pitch = 89.0f;
	if (Pitch < -89.0f) Pitch = -89.0f;
	InternalUpdate();
}

void Camera::ProcessMouseScroll(float yoffset)
{
	Fovy -= (float)yoffset;
	if (Fovy < 1.0f) Fovy = 1.0f;
	if (Fovy > 45.0f) Fovy = 45.0f;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	Camera::ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	Camera::ProcessMouseScroll(yoffset);
}