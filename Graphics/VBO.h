#pragma once

#include <glad/glad.h>

// Store vertices in GPU memory
class VBO
{
public:
	void Bind();
	void Unbind();
	void Delete();
	VBO(GLfloat* vertices, GLsizeiptr size, GLenum dataType);
	~VBO();
private:
	// Reference ID of the Vertex Buffer Object
	GLuint _ID = 0;
};