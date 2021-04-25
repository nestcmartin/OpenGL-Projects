#include "DirectionalLight.h"

glm::vec3 DirectionalLight::direction(-0.2f, -1.0f, -0.3f);
glm::vec3 DirectionalLight::ambient(0.2f, 0.2f, 0.2f);
glm::vec3 DirectionalLight::diffuse(0.5f, 0.5f, 0.5f);
glm::vec3 DirectionalLight::specular(1.0f, 1.0f, 1.0f);

void DirectionalLight::Init(const glm::vec3& dir, const glm::vec3& amb, const glm::vec3& diff, const glm::vec3& spec)
{
	direction = dir;
	ambient = amb;
	diffuse = diff;
	specular = spec;
}

void DirectionalLight::Release()
{
}