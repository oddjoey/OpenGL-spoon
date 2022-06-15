#pragma once

#include <memory>

#include "cObjectManager.h"

class cWorldManager
{
	static std::shared_ptr<cWorldManager> _instance;
public:
	static std::shared_ptr<cWorldManager> Get();

	std::shared_ptr<cObjectManager> GetObjectManager();

	cWorldManager();
	~cWorldManager();

	void CreateWorld();
private:
	std::shared_ptr<cObjectManager> _objectManager = nullptr;
};