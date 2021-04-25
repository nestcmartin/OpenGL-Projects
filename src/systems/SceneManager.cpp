#include "Scene.h"
#include "SceneManager.h"

Scene* SceneManager::currentScene_ = nullptr;
std::vector<Scene*> SceneManager::scenes_;

void SceneManager::Init()
{
	Scene* scene = new Scene("Main Scene");
	scenes_.push_back(scene);
	LoadScene(0);
}

void SceneManager::Release()
{
	for (Scene* scene : scenes_)
	{
		delete scene;
	}
	scenes_.clear();
}

void SceneManager::Update(float deltaTime)
{
	currentScene_->update(deltaTime);
}

void SceneManager::LoadScene(unsigned int index)
{
	currentScene_ = scenes_.at(index);
}