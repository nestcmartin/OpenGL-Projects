#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Lamp.h"
#include "Renderer.h"
#include "Shader.h"

glm::vec3 lightColor(1.0f);

Lamp::Lamp(RenderData* rd) : RenderableObject(rd)
{
	rd_->shader->bind();
	rd_->shader->setVec3("lightColor", lightColor);
}

Lamp::~Lamp()
{
}

void Lamp::update(float deltaTime)
{
	//lightColor.x = sin(glfwGetTime() * 2.0f);
	//lightColor.y = sin(glfwGetTime() * 0.7f);
	//lightColor.z = sin(glfwGetTime() * 1.3f);

	//rd_->shader->bind();
	//rd_->shader->setVec3("lightColor", lightColor);
}
