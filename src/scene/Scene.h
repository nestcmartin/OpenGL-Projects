#ifndef __SCENE_H__
#define __SCENE_H__

#include <vector>

class Camera;
class RenderableObject;

class Scene
{
	friend class SceneManager;

public:
	Scene(const char* name);
	~Scene();

	void addObject(RenderableObject* obj);

	void update(float deltaTime);

private:
	const char* name_;
	const unsigned int id_;
	
	static unsigned int index;

	Camera* mainCamera_;
	std::vector<RenderableObject*> objects_;
};

#endif // !__SCENE_H__