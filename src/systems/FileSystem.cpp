#include <unordered_map>

#include "FileSystem.h"
#include "Shader.h"
#include "Texture.h"

std::unordered_map<const char*, Shader*> Shaders;
std::unordered_map<const char*, Texture*> Textures;

void FileSystem::Init()
{
	Shaders["BasicShader"] = new Shader();
	Shaders["color_triangle"] = new Shader("assets/shaders/color_triangle.vs", "assets/shaders/color_triangle.fs");
	Shaders["container"] = new Shader("assets/shaders/container3D.vs", "assets/shaders/container3D.fs");
	Shaders["cube"] = new Shader("assets/shaders/cube.vs", "assets/shaders/cube.fs");
	Shaders["light_cube"] = new Shader("assets/shaders/light_cube.vs", "assets/shaders/light_cube.fs");
	Shaders["light_source"] = new Shader("assets/shaders/light_source.vs", "assets/shaders/light_source.fs");
	Shaders["material_cube"] = new Shader("assets/shaders/material_cube.vs", "assets/shaders/material_cube.fs");
	Shaders["light_cubes"] = new Shader("assets/shaders/light_cubes.vs", "assets/shaders/light_cubes.fs");

	Textures["container"] = new Texture("assets/textures/container.jpg");
	Textures["face"] = new Texture("assets/textures/awesomeface.png");
	Textures["container2"] = new Texture("assets/textures/container2.png");
	Textures["container2_specular"] = new Texture("assets/textures/container2_specular.png");
	Textures["lighting_maps_specular_color"] = new Texture("assets/textures/lighting_maps_specular_color.png");
	Textures["matrix"] = new Texture("assets/textures/matrix.jpg");
}

void FileSystem::Release()
{
	for (auto t : Textures)
	{
		delete t.second;
	}
	Textures.clear();

	for (auto s : Shaders)
	{
		delete s.second;
	}
	Shaders.clear();
}

Shader* FileSystem::LoadShader(const char* key, const char* vs, const char* fs)
{
	if (Shaders.find(key) != Shaders.end())
	{
		delete Shaders[key];
	}

	Shader* shader = new Shader(vs, fs);
	Shaders[key] = shader;
	return shader;
}

Texture* FileSystem::LoadTexture(const char* key, const char* filename)
{
	if (Textures.find(key) != Textures.end())
	{
		delete Textures[key];
	}

	Texture* texture = new Texture(filename);
	Textures[key] = texture;
	return texture;
}

Shader* FileSystem::GetShader(const char* key)
{
	return Shaders[key];
}

Texture* FileSystem::GetTexture(const char* key)
{
	return Textures[key];
}