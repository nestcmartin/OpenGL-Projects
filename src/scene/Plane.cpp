#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.h"
#include "Input.h"
#include "Plane.h"
#include "Renderer.h"
#include "FileSystem.h"
#include "Shader.h"
#include "Texture.h"

Plane::Plane(RenderData* rd) :
	RenderableObject(rd),
	mixValue_(0.2f)
{
	textures_.push_back(FileSystem::GetTexture("container"));
	textures_.push_back(FileSystem::GetTexture("face"));

	for (size_t i = 0; i < textures_.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		textures_.at(i)->bind();
	}

	rd_->shader->bind();
	rd_->shader->setInt("texture1", 0);
	rd_->shader->setInt("texture2", 1);

	//model_ = glm::rotate(model_, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
}

Plane::~Plane()
{
}

void Plane::update(float deltaTime)
{
	if (Input::IsKeyDown(GLFW_KEY_UP))
		mixValue_ += MIX_INCREMENT * deltaTime;
	if (Input::IsKeyDown(GLFW_KEY_DOWN))
		mixValue_ -= MIX_INCREMENT * deltaTime;

	rd_->shader->bind();
	rd_->shader->setFloat("mixValue", mixValue_);
}

void Plane::render()
{
	RenderableObject::render();
}