#include "cModelManager.h"

std::shared_ptr<cModelManager> cModelManager::_instance = nullptr;

std::shared_ptr<cModelManager> cModelManager::Get()
{
	if (_instance == nullptr)
		_instance = std::make_shared<cModelManager>();

	return _instance;
}

std::shared_ptr<Model> cModelManager::CreateModel(std::vector<GLfloat> vertices, std::vector<GLfloat> textureCoords, std::vector<GLuint> indices)
{
	auto vao = std::make_shared<VAO>();
	_vaos.push_back(vao);
	auto indicesVBO = std::make_shared<VBO>(GL_ELEMENT_ARRAY_BUFFER);
	_vbos.push_back(indicesVBO);
	auto verticesVBO = std::make_shared<VBO>(GL_ARRAY_BUFFER);
	_vbos.push_back(verticesVBO);
	auto textureVBO = std::make_shared<VBO>(GL_ARRAY_BUFFER);
	_vbos.push_back(textureVBO);
	
	vao->Bind();

	indicesVBO->Bind();
	indicesVBO->SetBufferData(indices, indices.size() * sizeof(GLuint), GL_STATIC_DRAW);

	verticesVBO->Bind();
	verticesVBO->SetBufferData(vertices, vertices.size() * sizeof(GLfloat), GL_STATIC_DRAW);
	vao->LinkAttribute(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	textureVBO->Bind();
	textureVBO->SetBufferData(textureCoords, textureCoords.size() * sizeof(GLfloat), GL_STATIC_DRAW);
	vao->LinkAttribute(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	vao->Unbind();

	return std::make_shared<Model>(vao, static_cast<GLuint>(indices.size()));
}

std::shared_ptr<Texture> cModelManager::CreateTexture(const std::string& path)
{
	auto texture = std::make_shared<Texture>(path, GL_TEXTURE_2D);
	_textures.push_back(texture);
	return texture;
}

cModelManager::cModelManager()
{
}

cModelManager::~cModelManager()
{
}
