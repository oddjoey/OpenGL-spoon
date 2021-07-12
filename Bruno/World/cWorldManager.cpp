#include "cWorldManager.h"

std::shared_ptr<cWorldManager> cWorldManager::_instance = nullptr;

std::shared_ptr<cWorldManager> cWorldManager::Get()
{
	if (_instance == nullptr)
		_instance = std::make_shared<cWorldManager>();

	return _instance;
}

std::shared_ptr<cObjectManager> cWorldManager::GetObjectManager()
{
	if (_objectManager == nullptr)
		_objectManager = std::make_shared<cObjectManager>();

	return _objectManager;
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
