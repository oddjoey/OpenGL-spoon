#pragma once

#include <glad/glad.h>

// Attribute list or array of buffers (VBOS)
class VAO
{
public:
	// Links a VBO Attribute such as a position or color to the VAO
	void LinkAttribute(const GLuint& index, const GLuint& numOfComponents, const GLenum& type, const GLenum& normalize, const GLsizei& stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
	// Generate a VAO ID
	VAO();
	~VAO();

	GLuint GetID() const;
private:
	// Reference ID for the Vertex Array Object
	GLuint _ID = 0;
};

