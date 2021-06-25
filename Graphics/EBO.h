#pragma once

#include <glad/glad.h>

class EBO
{
public:
	void Bind();
	void Unbind();
	void Delete();
	// Generates an Elements Buffer Object and links indices
	EBO(GLuint* indices, GLsizeiptr size);

private:
	// ID reference of the Elements Buffer Object
	GLuint _ID;
};

