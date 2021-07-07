#include "Bruno.h"

std::shared_ptr<cBrunoEngine> cBrunoEngine::_instance = nullptr;


std::shared_ptr<cBrunoEngine> cBrunoEngine::GetEngine()
{
	if (_instance == nullptr)
		_instance = std::make_shared<cBrunoEngine>();

	return _instance;
}

std::shared_ptr<cWindowManager> cBrunoEngine::GetWindowManager()
{
	return cWindowManager::Get();
}

std::shared_ptr<cWorldManager> cBrunoEngine::GetWorldManager()
{
	return cWorldManager::Get();
}

cBrunoEngine::cBrunoEngine()
{
}

cBrunoEngine::~cBrunoEngine()
{
}
