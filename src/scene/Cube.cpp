#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "Shader.h"
#include "Texture.h"

#include "Cube.h"
#include "FileSystem.h"
#include "Renderer.h"


glm::vec3 cubePositions[] = {
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(2.0f, 5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f, 3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f, 2.0f, -2.5f),
	glm::vec3(1.5f, 0.2f, -1.5f),
	glm::vec3(-1.3f, 1.0f, -1.5f)
};

Cube::Cube(RenderData* rd) : RenderableObject(rd)
{
	// Textures
	textures_.push_back(FileSystem::GetTexture("container2"));
	textures_.push_back(FileSystem::GetTexture("container2_specular"));

	for (size_t i = 0; i < textures_.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		textures_.at(i)->bind();
	}

	rd_->shader->bind();

	// Material
	rd_->shader->setInt("material.diffuse", 0);
	rd_->shader->setInt("material.specular", 1);
	rd_->shader->setInt("material.emission", 2);
	rd_->shader->setFloat("material.shininess", 64.0f);
}

Cube::~Cube()
{
}

void Cube::update(float deltaTime)
{
	rd_->shader->bind();
	rd_->shader->setVec3("viewPos", Camera::GetPosition());
	rd_->shader->setVec3("light.position", Camera::GetPosition());
	rd_->shader->setVec3("light.direction", Camera::GetDirection());
	rd_->shader->setVec3("light.ambient", PointLight::Ambient());
	rd_->shader->setVec3("light.diffuse", PointLight::Diffuse());
	rd_->shader->setVec3("light.specular", PointLight::Specular());
	rd_->shader->setFloat("light.constant", PointLight::ConstantAttenuation());
	rd_->shader->setFloat("light.linear", PointLight::LinearAttenuation());
	rd_->shader->setFloat("light.quadratic", PointLight::QuadraticAttenuation());
	rd_->shader->setFloat("light.cutOff", glm::cos(glm::radians(12.5f)));
	rd_->shader->setFloat("light.outerCutOff;", glm::cos(glm::radians(17.5f)));
}	

void Cube::render()
{
	for (size_t i = 0; i < 10; i++)
	{
		model_ = glm::mat4(1.0f);
		translate(cubePositions[i]);
		rotate(20.0f * i, glm::vec3(1.0f, 0.3f, 0.5f));
		RenderableObject::render();
	}
}