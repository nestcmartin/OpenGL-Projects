#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include <vector>

class RenderableObject;
class Scene;

class SceneManager
{
public:
	static void Init();
	static void Release();

	static void Update(float deltaTime);
	static void LoadScene(unsigned int index);

private:
	static Scene* currentScene_;
	static std::vector<Scene*> scenes_;
};

#endif // !__SCENE_MANAGER_H__

