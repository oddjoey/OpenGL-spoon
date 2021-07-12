#pragma once

#include <glad/glad.h>

class EBO
{
public:
	void Bind();
	void Unbind();
	void Delete();
	// Generates an Elements Buffer Object and links indices
	EBO(GLuint* indices, const GLsizeiptr& size, const GLenum& dataType);
	~EBO();
private:
	// ID reference of the Elements Buffer Object
	GLuint _ID;
};

