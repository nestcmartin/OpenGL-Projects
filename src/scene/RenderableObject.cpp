#include <glm/gtc/matrix_transform.hpp>

#include "Camera.h"
#include "RenderableObject.h"
#include "Renderer.h"
#include "Shader.h"

RenderableObject::RenderableObject(RenderData* rd) : rd_(rd), model_(glm::mat4(1.0f))
{
}

RenderableObject::~RenderableObject()
{
	delete rd_;
}

void RenderableObject::render()
{	
	rd_->shader->bind();
	rd_->shader->setMat4("model", model_);
	rd_->shader->setMat4("view", Camera::ViewMatrix());
	rd_->shader->setMat4("proj", Camera::ProjectionMatrix());
	Renderer::Draw(rd_->vao, rd_->count, rd_->shader->getId());
}

void RenderableObject::translate(const glm::vec3& position)
{
	model_ = glm::translate(model_, position);
}

void RenderableObject::translate(float x, float y, float z)
{
	model_ = glm::translate(model_, glm::vec3(x, y, z));
}

void RenderableObject::rotate(float angle, const glm::vec3& axis)
{
	model_ = glm::rotate(model_, glm::radians(angle), axis);
}

void RenderableObject::rotate(float angle, float x, float y, float z)
{
	model_ = glm::rotate(model_, glm::radians(angle), glm::vec3(x, y, z));
}

void RenderableObject::scale(const glm::vec3& scale)
{
	model_ = glm::scale(model_, scale);
}

void RenderableObject::scale(float x, float y, float z)
{
	model_ = glm::scale(model_, glm::vec3(x, y, z));
}

void RenderableObject::scale(float scale)
{
	model_ = glm::scale(model_, glm::vec3(scale, scale, scale));
}
