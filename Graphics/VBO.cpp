#include "VBO.h"

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, _ID);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &_ID);
}

VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	// Generate a vertex buffer object
	glGenBuffers(1, &_ID);

	// Introducing vertices into the VBO
	glBindBuffer(GL_ARRAY_BUFFER, _ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
