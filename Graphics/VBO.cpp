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

VBO::VBO(GLfloat* vertices, GLsizeiptr size, GLenum dataType)
{
	// Generate a vertex buffer object
	glGenBuffers(1, &_ID);

	// Tell OpenGL to use our current buffer as GL_ARRAY_BUFFER
	// Any function calls to GL_ARRAY_BUFFER are now bound to this buffer
	glBindBuffer(GL_ARRAY_BUFFER, _ID);

	// Size of vertex data
	//GLsizeiptr dataSize = sizeof(vertices);

	// Copy vertex data from vertices and store it to our current buffer in GL_ARRAY_BUFFER
	// We input the size (in bytes) of the vertex data along with the actual data
	// GL_STREAM_DRAW	->	data changed once, used few times
	// GL_STATIC_DRAW	->	data changed once, used many times.
	// GL_DYNAMIC_DRAW	->	data changed alot, used many times.
	glBufferData(GL_ARRAY_BUFFER, size, vertices, dataType);

	// Unbind buffer to prevent unwanted modification
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
}
