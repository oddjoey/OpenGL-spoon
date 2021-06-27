#pragma once

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "Shader.h"

class Texture
{
public:
	void SetUniform(Shader& shader, const char* uniformName, GLuint value);
	void Bind();
	void Unbind();
	void Delete();

	Texture(const char* imageName, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType);

private:
	GLuint _ID		= 0;
	GLenum _type	= 0;
};