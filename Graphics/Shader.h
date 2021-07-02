#pragma once

#include<glad/glad.h>

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string getFileContents(const char* fileName);
// Checks if the different Shaders have compiled properly
void CheckCompileErrors(unsigned int shader, const char* type);

class Shader
{
public:
	void Activate();
	void Delete();

	// Returns ID
	GLuint GetID() const;

	// Builds shaders w/ two different shader sources
	Shader(const char* vertexFile, const char* fragmentFile);
private:
	GLuint _ID = 0;
	GLuint _vertexShaderID, _fragmentShaderID = 0;
};