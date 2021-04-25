#ifndef __CUBE_H__
#define __CUBE_H__

#include <vector>

#include "RenderableObject.h"

class Texture;

class Cube : public RenderableObject
{
public:
	Cube(RenderData* rd);
	virtual ~Cube();

	void update(float deltaTime) override;
	void render() override;

private:
	std::vector<Texture*> textures_;
};

#endif // !__CUBE_H__