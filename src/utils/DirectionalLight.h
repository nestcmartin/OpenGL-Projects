#ifndef __DRIECTIONAL_LIGHT_H__
#define __DRIECTIONAL_LIGHT_H__

#include <glm/glm.hpp>

class DirectionalLight
{
public:
	static void Init(const glm::vec3& dir = { -0.2f, -1.0f, -0.3f }, const glm::vec3& amb = { 0.2f, 0.2f, 0.2f },
		const glm::vec3& diff = { 0.5f, 0.5f, 0.5f }, const glm::vec3& spec = { 1.0f, 1.0f, 1.0f });
	static void Release();

	inline static const glm::vec3& Direction() { return direction; }
	inline static const glm::vec3& Ambient() { return ambient; }
	inline static const glm::vec3& Diffuse() { return diffuse; }
	inline static const glm::vec3& Specular() { return specular; }

	inline static void SetDirection(const glm::vec3& dir) { direction = dir; }
	inline static void SetDirection(float x, float y, float z) { direction = glm::vec3(x, y, z); }
	inline static void SetAmbient(const glm::vec3& amb) { ambient = amb; }
	inline static void SetAmbient(float x, float y, float z) { ambient = glm::vec3(x, y, z); }
	inline static void SetDiffuse(const glm::vec3& diff) { diffuse = diff; }
	inline static void SetDiffuse(float x, float y, float z) { diffuse = glm::vec3(x, y, z); }
	inline static void SetSpecular(const glm::vec3& spec) { specular = spec; }
	inline static void SetSpecular(float x, float y, float z) { specular = glm::vec3(x, y, z); }

private:
	static glm::vec3 direction;
	static glm::vec3 ambient;
	static glm::vec3 diffuse;
	static glm::vec3 specular;
};

#endif // !__DRIECTIONAL_LIGHT_H__

