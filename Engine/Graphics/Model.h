#pragma once

#include <memory>

#include "VAO.h"
#include "VBO.h"

#include "Texture.h"

class Model
{
	Model() = delete;
public:
	// Must be called in cWindowManager.Render
	Model* Render();

	Model* SetTexture(const std::shared_ptr<Texture>& texture);
	std::shared_ptr<Texture> GetTexture() const;

	std::shared_ptr<VAO> GetVAO() const;
	GLuint GetVertexCount() const;

	Model(std::shared_ptr<VAO> vao, const GLuint& vertexCount);
	~Model();
private:
	std::shared_ptr<VAO> _vao = nullptr;
	GLuint _vertexCount = 0;
	std::shared_ptr<Texture> _texture = nullptr;
};