#ifndef __POINT_LIGHT_H__
#define __POINT_LIGHT_H__

#include <glm/glm.hpp>

class PointLight
{
public:
	static void Init(const glm::vec3& pos = { -0.2f, -1.0f, -0.3f }, const glm::vec3& amb = { 0.2f, 0.2f, 0.2f },
		const glm::vec3& diff = { 0.5f, 0.5f, 0.5f }, const glm::vec3& spec = { 1.0f, 1.0f, 1.0f },
		float con = 1.0f, float lin = 0.09f, float quad = 0.032f);
	static void Release();

	inline static const glm::vec3& Position() { return position; }
	inline static const glm::vec3& Ambient() { return ambient; }
	inline static const glm::vec3& Diffuse() { return diffuse; }
	inline static const glm::vec3& Specular() { return specular; }
	inline static float ConstantAttenuation() { return constant; }
	inline static float LinearAttenuation() { return linear; }
	inline static float QuadraticAttenuation() { return quadratic; }

	inline static void SetPosition(const glm::vec3& pos) { position = pos; }
	inline static void SetPosition(float x, float y, float z) { position = glm::vec3(x, y, z); }
	inline static void SetAmbient(const glm::vec3& amb) { ambient = amb; }
	inline static void SetAmbient(float x, float y, float z) { ambient = glm::vec3(x, y, z); }
	inline static void SetDiffuse(const glm::vec3& diff) { diffuse = diff; }
	inline static void SetDiffuse(float x, float y, float z) { diffuse = glm::vec3(x, y, z); }
	inline static void SetSpecular(const glm::vec3& spec) { specular = spec; }
	inline static void SetSpecular(float x, float y, float z) { specular = glm::vec3(x, y, z); }
	inline static void SetConstantAttenuation(float att) { constant = att; }
	inline static void SetLinearAttenuation(float att) { linear = att; }
	inline static void SetQuadraticAttenuation(float att) { quadratic = att; }

private:
	static glm::vec3 position;
	static glm::vec3 ambient;
	static glm::vec3 diffuse;
	static glm::vec3 specular;

	static float constant;
	static float linear;
	static float quadratic;
};

#endif // !__POINT_LIGHT_H__