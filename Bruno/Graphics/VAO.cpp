#include "VAO.h"

void VAO::LinkAttrib(VBO& vbo, GLuint index, GLuint numOfComponents, GLenum type, GLenum normalize, GLsizei stride, void* offset)
{
	vbo.Bind();
	glVertexAttribPointer(index, numOfComponents, type, normalize, stride, offset);
	glEnableVertexAttribArray(index);
	vbo.Unbind();
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

VAO::~VAO()
{
	Delete();
}
