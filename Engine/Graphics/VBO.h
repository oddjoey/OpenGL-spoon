#pragma once

#include <glad/glad.h>
#include <vector>

// Store data in buffers which are store in the GPU
class VBO
{
public:
	void Bind();
	void Unbind();
	void Delete();
	void SetBufferData(std::vector<GLfloat> data, const GLsizeiptr& size, const GLenum& dataType);
	void SetBufferData(std::vector<GLuint> data, const GLsizeiptr& size, const GLenum& dataType);
	GLuint GetID() const;
	VBO(const GLenum& targetType);
	~VBO();
private:
	// Reference ID of the Vertex Buffer Object
	GLuint _ID = 0;
	GLenum _type = 0;
};