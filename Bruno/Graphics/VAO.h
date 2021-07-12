#pragma once

#include "VBO.h"

class VAO
{
public:
	// Links a VBO Attribute such as a position or color to the VAO
	void LinkAttrib(VBO& VBO, const GLuint& index, const GLuint& numOfComponents, const GLenum& type, const GLenum& normalize, const GLsizei& stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
	// Generate a VAO ID
	VAO();
	~VAO();
private:
	// Reference ID for the Vertex Array Object
	GLuint _ID;
};

