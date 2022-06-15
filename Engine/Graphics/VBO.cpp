#include "VBO.h"

void VBO::Bind()
{
	glBindBuffer(_type, _ID);
}

void VBO::Unbind()
{
	glBindBuffer(_type, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &_ID);
}

void VBO::SetBufferData(std::vector<GLfloat> data, const GLsizeiptr& size, const GLenum& dataType)
{
	//// Copy vertex data from vertices and store it to our current buffer in GL_ARRAY_BUFFER
	//// We input the size (in bytes) of the vertex data along with the actual data
	//// GL_STREAM_DRAW	->	data changed once, used few times
	//// GL_STATIC_DRAW	->	data changed once, used many times.
	//// GL_DYNAMIC_DRAW	->	data changed alot, used many times.
	glBufferData(_type, size, data.data(), dataType);
}

void VBO::SetBufferData(std::vector<GLuint> data, const GLsizeiptr& size, const GLenum& dataType)
{
	//// Copy vertex data from vertices and store it to our current buffer in GL_ARRAY_BUFFER
	//// We input the size (in bytes) of the vertex data along with the actual data
	//// GL_STREAM_DRAW	->	data changed once, used few times
	//// GL_STATIC_DRAW	->	data changed once, used many times.
	//// GL_DYNAMIC_DRAW	->	data changed alot, used many times.
	glBufferData(_type, size, data.data(), dataType);
}

GLuint VBO::GetID() const
{
	return _ID;
}

VBO::VBO(const GLenum& targetType)
{
	_type = targetType;

	//// Generate buffer and store id
	glGenBuffers(1, &_ID);
}

VBO::~VBO()
{
	Delete();
}
