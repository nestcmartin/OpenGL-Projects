#ifndef __PLANE_H__
#define __PLANE_H__

#include <vector>

#include "RenderableObject.h"

class Texture;

class Plane : public RenderableObject
{
public:
	Plane(RenderData* rd);
	virtual ~Plane();

	void update(float deltaTime) override;
	void render() override;

private:
	std::vector<Texture*> textures_;
	const float MIX_INCREMENT = 0.2f;
	float mixValue_;
};

#endif // !__PLANE_H__