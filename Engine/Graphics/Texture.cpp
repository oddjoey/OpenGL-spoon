#include "Texture.h"

void Texture::Bind(const GLuint& slot)
{
	_slot = GL_TEXTURE0 + slot;
	glActiveTexture(_slot);
	glBindTexture(_type, _ID);
}

void Texture::Unbind()
{
	glBindTexture(_type, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &_ID);
}

GLuint Texture::GetSlot() const
{
	return _slot;
}

Texture::Texture(const std::string& path, const GLenum& textureType)
	: _type(textureType)
{
	/* Texture Stuffs */
	stbi_set_flip_vertically_on_load(true);
	unsigned char* imgBytes = stbi_load(path.c_str(), &_width, &_height, &_clrCh, 0);	// Loading our texture with stb

	if (!imgBytes)
		return;

	glGenTextures(1, &_ID);	// Generating textures
	Bind();	// Bind texture

	// How our texture is scaled
	glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Scaling texture down
	glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// Scaling up
	// How our texture is repeatedHow our texture is repeated
	glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	// X
	glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	// Y

	glTexImage2D(textureType, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgBytes);
	Unbind();

	stbi_image_free(imgBytes);
}

Texture::~Texture()
{
	Delete();
}
