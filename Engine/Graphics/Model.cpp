#include "Model.h"

Model::Model(std::shared_ptr<VAO> vao, const GLuint& vertexCount) : _vao(vao), _vertexCount(vertexCount)
{
}

Model::~Model()
{
}

Model* Model::Render()
{
	_vao->Bind();

	if (_texture != nullptr)
		_texture->Bind();

	glDrawElements(GL_TRIANGLES, _vertexCount, GL_UNSIGNED_INT, 0);

	_vao->Unbind();

	return this;
}

Model* Model::SetTexture(const std::shared_ptr<Texture>& texture)
{
	_texture = texture;
	return this;
}

std::shared_ptr<Texture> Model::GetTexture() const
{
	return _texture;
}

std::shared_ptr<VAO> Model::GetVAO() const
{
	return _vao;
}

GLuint Model::GetVertexCount() const
{
	return _vertexCount;
}

