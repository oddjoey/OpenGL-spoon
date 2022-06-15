#pragma once

#include <memory>

#include "Graphics/cWindowManager.h"
#include "World/cWorldManager.h"
#include "Graphics/cModelManager.h"

class cEngine
{
	static std::shared_ptr<cEngine>	_instance;
public:
	static std::shared_ptr<cEngine>	GetEngine();
	std::shared_ptr<cWindowManager>	GetWindowManager();
	std::shared_ptr<cWorldManager>	GetWorldManager();

	cEngine();
	~cEngine();

private:

};