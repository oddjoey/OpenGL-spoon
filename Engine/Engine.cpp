#include "Engine.h"

std::shared_ptr<cEngine> cEngine::_instance = nullptr;

std::shared_ptr<cEngine> cEngine::GetEngine()
{
	if (_instance == nullptr)
		_instance = std::make_shared<cEngine>();

	return _instance;
}

std::shared_ptr<cWindowManager> cEngine::GetWindowManager()
{
	return cWindowManager::Get();
}

std::shared_ptr<cWorldManager> cEngine::GetWorldManager()
{
	return cWorldManager::Get();
}

cEngine::cEngine()
{
}

cEngine::~cEngine()
{
}
