#include "VAO.h"

void VAO::LinkAttribute(const GLuint& index, const GLuint& numOfComponents, const GLenum& type, const GLenum& normalize, const GLsizei& stride, void* offset)
{
	glVertexAttribPointer(index, numOfComponents, type, normalize, stride, offset);
	glEnableVertexAttribArray(index);
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

GLuint VAO::GetID() const
{
	return _ID;
}
