#pragma once

#include <glad/glad.h>

class VBO
{
public:
	void Bind();
	void Unbind();
	void Delete();
	// Generates a Vertex Buffer Object and links vertices
	VBO(GLfloat* vertices, GLsizeiptr size);
private:
	// Reference ID of the Vertex Buffer Object
	GLuint _ID = 0;
};