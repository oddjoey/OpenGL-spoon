#pragma once

#include "cModelManager.h"

class cGraphicsManager
{
	static std::shared_ptr<cGraphicsManager> _instance;
public:
	static std::shared_ptr<cGraphicsManager> Get();

	std::shared_ptr<cModelManager> GetModelManager();

	std::shared_ptr<Shader> CreateShader(const char* vertexFile, const char* fragmentFile);
	std::shared_ptr<Shader> GetShader(const GLuint index = 0) const;

	std::shared_ptr<Texture> CreateTexture(const char* textureFile);

	cGraphicsManager();
	~cGraphicsManager();
private:
	std::vector<std::shared_ptr<Shader>> _shaders = {};
};

