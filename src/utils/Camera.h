#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <glm/glm.hpp>

class Camera
{
public:
	static void Init(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f);
	static void Release();

	static glm::mat4 ViewMatrix();
	static glm::mat4 ProjectionMatrix();

	static void Update(float deltaTime);

	static void ProcessMouseMovement(float xoffset, float yoffset);
	static void ProcessMouseScroll(float yoffset);

	static const glm::vec3& GetPosition() { return Position; }
	static const glm::vec3& GetDirection() { return Front; }

private:
	static void InternalUpdate();

protected:
	static glm::vec3 WorldUp;
	static glm::vec3 Position;
	static glm::vec3 Front;
	static glm::vec3 Up;
	static glm::vec3 Right;

	static float Yaw;
	static float Pitch;
	static float Roll;

	static float Fovy;
	static float AspectRatio;
	static float Near;
	static float Far;
	static bool Ortographic;

	static float MovementSpeed;
	static float MouseSensitivity;
};

#endif // !__CAMERA_H__