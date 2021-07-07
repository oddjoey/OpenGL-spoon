#include "Texture.h"

void Texture::SetUniform(Shader& shader, const char* uniformName, GLuint value)
{
	// Gets the location of the uniform
	GLuint texUni = glGetUniformLocation(shader.GetID(), uniformName);
	// Shader needs to be activated before changing the value of a uniform
	shader.Activate();
	// Sets the value of the uniform
	glUniform1i(texUni, value);
}

void Texture::Bind()
{
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

Texture::Texture(const char* imageName, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType)
{
	/* Texture Stuffs */
	_type = textureType;
	int imgWidth, imgHeight, imgColCh;															// Important information about our texture/image
	stbi_set_flip_vertically_on_load(true);
	unsigned char* imgBytes = stbi_load(imageName, &imgWidth, &imgHeight, &imgColCh, 0);			// Loading our texture with stb

	glGenTextures(1, &_ID);																// Generating textures
	glActiveTexture(slot);																// Assign texture to slot
	glBindTexture(textureType, _ID);													// Type of texture

	glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);							// How our texture is scaled
	glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);							//	

	// Extra lines in case you choose to use GL_CLAMP_TO_BORDER
	// float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

	glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_REPEAT);								// How our texture is repeated
	glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_REPEAT);								//

	glTexImage2D(textureType, 0, GL_RGBA, imgWidth, imgHeight, 0, format, pixelType, imgBytes);
	glGenerateMipmap(textureType);

	stbi_image_free(imgBytes);
	glBindTexture(textureType, 0);
}

Texture::~Texture()
{
	Delete();
}
