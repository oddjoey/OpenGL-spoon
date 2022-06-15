#pragma once

#include <memory>
#include <vector>

#include "Model.h"
#include "Texture.h"

class cModelManager
{
	static std::shared_ptr<cModelManager> _instance;
public:
	static std::shared_ptr<cModelManager> Get();

	std::shared_ptr<Model> CreateModel(std::vector<GLfloat> vertices, std::vector<GLfloat> textureCoords, std::vector<GLuint> indices);
	std::shared_ptr<Texture> CreateTexture(const std::string& path);

	cModelManager();
	~cModelManager();
private:
	std::vector<std::shared_ptr<VAO>> _vaos = {};
	std::vector<std::shared_ptr<VBO>> _vbos = {};
	std::vector<std::shared_ptr<Texture>> _textures = {};
};

