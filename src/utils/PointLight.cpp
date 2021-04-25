#include "PointLight.h"

glm::vec3 PointLight::position(1.2f, 1.0f, 2.0f);
glm::vec3 PointLight::ambient(0.2f, 0.2f, 0.2f);
glm::vec3 PointLight::diffuse(0.5f, 0.5f, 0.5f);
glm::vec3 PointLight::specular(1.0f, 1.0f, 1.0f);

float PointLight::constant = 1.0f;
float PointLight::linear = 0.09f;
float PointLight::quadratic = 0.032f;

void PointLight::Init(const glm::vec3& pos, const glm::vec3& amb, const glm::vec3& diff, const glm::vec3& spec, float con, float lin, float quad)
{
	position = pos;
	ambient = amb;
	diffuse = diff;
	specular = spec;
}

void PointLight::Release()
{
}