#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

class Shader;
class Texture;

class FileSystem
{
public:
	static void Init();
	static void Release();

	static Shader* LoadShader(const char* key, const char* vs, const char* fs);
	static Texture* LoadTexture(const char* key, const char* filename);
	static Shader* GetShader(const char* key);
	static Texture* GetTexture(const char* key);
};

#endif // !__FILE_SYSTEM_H__