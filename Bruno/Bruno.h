#pragma once

#include <memory>

#include "Graphics/Window.h"
#include "World/World.h"

class cBrunoEngine
{
	static std::shared_ptr<cBrunoEngine>	_instance;
public:
	static std::shared_ptr<cBrunoEngine>	GetEngine();
	static std::shared_ptr<cWindowManager>	GetWindowManager();
	static std::shared_ptr<cWorldManager>	GetWorldManager();

	cBrunoEngine();
	~cBrunoEngine();

private:

};