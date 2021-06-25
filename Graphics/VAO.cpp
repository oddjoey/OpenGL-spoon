#include "VAO.h"

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numOfComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numOfComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(_ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &_ID);
}

VAO::VAO()
{
	glGenVertexArrays(1, &_ID);
}
