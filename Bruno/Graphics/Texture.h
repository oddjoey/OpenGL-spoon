#pragma once

#include <stb/stb_image.h>

#include "Shader.h"

class Texture
{
public:
	void SetUniform(Shader& shader, const char* uniformName, const GLuint& value);
	void Bind();
	void Unbind();
	void Delete();

	Texture(const char* imageName, const GLenum& textureType, const GLenum& slot, const GLenum& format, const GLenum& pixelType);
	~Texture();
private:
	GLuint _ID		= 0;
	GLenum _type	= 0;
};