#ifndef __RENDERABLE_OBJECT_H__
#define __RENDERABLE_OBJECT_H__

#include <glm/glm.hpp>

#include "Object.h"

struct RenderData;

class RenderableObject : public Object
{
public:
	RenderableObject(RenderData* rd);
	virtual ~RenderableObject();

	virtual void update(float deltaTime) {}
	virtual void render();

	void translate(const glm::vec3& position);
	void translate(float x, float y, float z);
	void rotate(float angle, const glm::vec3& axis);
	void rotate(float angle, float x, float y, float z);
	void scale(const glm::vec3& scale);
	void scale(float x, float y, float z);
	void scale(float scale);

protected:
	RenderData* rd_;
	glm::mat4 model_;
};
 
#endif // !__RENDERABLE_OBJECT_H__