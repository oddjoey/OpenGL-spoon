#include "World.h"

std::shared_ptr<cWorldManager> cWorldManager::_instance = nullptr;

std::shared_ptr<cWorldManager> cWorldManager::Get()
{
	if (_instance == nullptr)
		_instance = std::make_shared<cWorldManager>();

	return _instance;
}

cWorldManager::cWorldManager()
{
}

cWorldManager::~cWorldManager()
{
}

void cWorldManager::CreateWorld()
{
}
