#include "Application.h"
#include "Input.h"
#include "Platform.h"
#include "Renderer.h"
#include "FileSystem.h"
#include "SceneManager.h"

void Application::Init()
{
	Platform::Init();
	Renderer::Init();
	Input::Init();
	FileSystem::Init();
	SceneManager::Init();
}

void Application::Release()
{
	SceneManager::Release();
	FileSystem::Release();
	Input::Release();
	Renderer::Release();
	Platform::Release();
}

void Application::Run()
{
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	while (!Platform::GetWindowShouldClose())
	{
		float currentFrame = Platform::GetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		Renderer::Clear();
		
		Input::Update(deltaTime);
		if (Input::IsKeyDown(256))
			Platform::SetWindowShouldClose(true);

		SceneManager::Update(deltaTime);
		Renderer::Present();
	}
}