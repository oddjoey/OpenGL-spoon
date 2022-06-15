#pragma once

#include <stb/stb_image.h>

#include "Shader.h"

class Texture
{
public:
	void Bind(const GLuint& slot = 0);
	void Unbind();
	void Delete();

	GLuint GetSlot() const;

	Texture(const std::string& path, const GLenum& textureType);
	~Texture();
private:
	GLuint	_ID		= 0;
	GLenum	_type	= 0;
	GLint	_width	= 0;
	GLint	_height = 0;
	GLint	_clrCh	= 0;
	GLuint  _slot	= 0;
};