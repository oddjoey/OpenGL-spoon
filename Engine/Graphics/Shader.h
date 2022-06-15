#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <unordered_map>

class Shader
{
	std::string getFileContents(const char* fileName);
	// Checks if the different Shaders have compiled properly
	void CheckCompileErrors(const unsigned int& shader, const char* type);
	GLint	 GetUniformLocation(const std::string& uniformName);
public:
	void Activate() const;
	void Delete() const;

	void SetUniform1i(const std::string& name, const GLint& value);
	void SetUniform1f(const std::string& name, const float& value);
	void SetUniform4f(const std::string& name, const float& v0, const float& v1, const float& v2, const float& v3);
	void BindAttribute(const GLuint& attribute, const char* variableName) const;

	// Returns ID
	GLuint GetID() const;

	// Builds shaders w/ two different shader sources
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();
private:
	GLuint _ID = 0;
	GLuint _vertexShaderID, _fragmentShaderID = 0;
	std::unordered_map<std::string, GLint> uniformLocationCache;
};