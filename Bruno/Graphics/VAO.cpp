#include "VAO.h"

void VAO::LinkAttrib(VBO& VBO, const GLuint& index, const GLuint& numOfComponents, const GLenum& type, const GLenum& normalize, const GLsizei& stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(index, numOfComponents, type, normalize, stride, offset);
	glEnableVertexAttribArray(index);
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

VAO::~VAO()
{
	Delete();
}
