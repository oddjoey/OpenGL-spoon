#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <memory>

std::string getFileContents(const char* fileName);

class Shaders
{
public:
	void Activate();
	void Delete();
	// Builds shaders w/ two different shader sources
	Shaders(const char* vertexFile, const char* fragmentFile);
private:
	// Checks if the different Shaders have compiled properly
	void CompileErrors(unsigned int shader, const char* type);
	GLuint _ID = 0;
	GLuint _vertexShader, _fragmentShader = 0;
};