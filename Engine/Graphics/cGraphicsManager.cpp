#include "cGraphicsManager.h"

std::shared_ptr<cGraphicsManager> cGraphicsManager::_instance = nullptr;

std::shared_ptr<cGraphicsManager> cGraphicsManager::Get()
{
	if (_instance == nullptr)
		_instance = std::make_shared<cGraphicsManager>();

	return _instance;
}

std::shared_ptr<cModelManager> cGraphicsManager::GetModelManager()
{
	return cModelManager::Get();
}

std::shared_ptr<Shader> cGraphicsManager::CreateShader(const char* vertexFile, const char* fragmentFile)
{
	auto shader = std::make_shared<Shader>(vertexFile, fragmentFile);

	_shaders.push_back(shader);

	return shader;
}

std::shared_ptr<Shader> cGraphicsManager::GetShader(const GLuint index) const
{
	return _shaders[index];
}

cGraphicsManager::cGraphicsManager()
{
}

cGraphicsManager::~cGraphicsManager()
{

}
