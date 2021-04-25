#ifndef __SHADER_H__
#define __SHADER_H__

#include <unordered_map>
#include <glm/glm.hpp>

class Shader
{
	enum ShaderType { VertexShader, FragmentShader };

public:
	Shader();
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	void bind() const;
	void unbind() const;
	
	void setBool(const char* name, bool value);
	void setInt(const char* name, int value);
	void setFloat(const char* name, float value);
	void setVec2(const char* name, const glm::vec2& value);
	void setVec2(const char* name, float x, float y);
	void setVec3(const char* name, const glm::vec3& value);
	void setVec3(const char* name, float x, float y, float z);
	void setVec4(const char* name, const glm::vec4& value);
	void setVec4(const char* name, float x, float y, float z, float w);
	void setMat2(const char* name, const glm::mat2& mat);
	void setMat3(const char* name, const glm::mat3& mat);
	void setMat4(const char* name, const glm::mat4& mat);

	inline unsigned int getId() const { return id_; }

private:
	void compileShader(unsigned int shader, ShaderType type);
	void linkShaders(unsigned int vertexShader, unsigned int fragmentShader);
	int getUniformLocation(const char* name);

private:
	unsigned int id_;
	std::unordered_map<const char*, unsigned int> uniformLocationCache_;
};

#endif // !__SHADER_H__