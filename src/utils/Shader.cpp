#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

Shader::Shader()
{
	// 1. Retrieve source code
	const char* vShaderCode = 
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	const char* fShaderCode = 
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		" FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";

	// 2. Compile shaders
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	compileShader(vertexShader, VertexShader);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	compileShader(fragmentShader, FragmentShader);

	// 3. Link shaders
	id_ = glCreateProgram();
	linkShaders(vertexShader, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	// 1. Retrieve source code
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		vShaderFile.close();
		fShaderFile.close();
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	// 2. Compile shaders
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	compileShader(vertexShader, VertexShader);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	compileShader(fragmentShader, FragmentShader);

	// 3. Link shaders
	id_ = glCreateProgram();
	linkShaders(vertexShader, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
	glDeleteProgram(id_);
}

void Shader::compileShader(unsigned int shader, ShaderType type)
{
	int success;
	char infoLog[512];
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		if (type == VertexShader) std::cerr << "ERROR::VERTEX_SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		else if (type == FragmentShader) std::cerr << "ERROR::FRAGMENT_SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

void Shader::linkShaders(unsigned int vertexShader, unsigned int fragmentShader)
{
	int success;
	char infoLog[512];
	glAttachShader(id_, vertexShader);
	glAttachShader(id_, fragmentShader);
	glLinkProgram(id_);
	glGetProgramiv(id_, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(id_, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
	}
}

int Shader::getUniformLocation(const char* name)
{
	if (uniformLocationCache_.find(name) != uniformLocationCache_.end())
		return uniformLocationCache_[name];

	int location = glGetUniformLocation(id_, name);
	uniformLocationCache_[name] = location;
	return location;	
}

void Shader::bind() const
{
	glUseProgram(id_);
}

void Shader::unbind() const
{
	glUseProgram(0);
}

void Shader::setBool(const char* name, bool value)
{
	glUniform1i(getUniformLocation(name), (int)value);
}

void Shader::setInt(const char* name, int value)
{
	glUniform1i(getUniformLocation(name), value);
}

void Shader::setFloat(const char* name, float value)
{
	glUniform1f(getUniformLocation(name), value);
}

void Shader::setVec2(const char* name, const glm::vec2& value)
{
	glUniform2fv(getUniformLocation(name), 1, &value[0]);
}

void Shader::setVec2(const char* name, float x, float y)
{
	glUniform2f(getUniformLocation(name), x, y);
}

void Shader::setVec3(const char* name, const glm::vec3& value)
{
	glUniform3fv(getUniformLocation(name), 1, &value[0]);
}

void Shader::setVec3(const char* name, float x, float y, float z)
{
	glUniform3f(getUniformLocation(name), x, y, z);
}

void Shader::setVec4(const char* name, const glm::vec4& value)
{
	glUniform4fv(getUniformLocation(name), 1, &value[0]);
}

void Shader::setVec4(const char* name, float x, float y, float z, float w)
{
	glUniform4f(getUniformLocation(name), x, y, z, w);
}

void Shader::setMat2(const char* name, const glm::mat2& mat)
{
	glUniformMatrix2fv(getUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat3(const char* name, const glm::mat3& mat)
{
	glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat4(const char* name, const glm::mat4& mat)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(mat));
}