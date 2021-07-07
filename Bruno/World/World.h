#pragma once

#include <memory>

class cWorldManager
{
	static std::shared_ptr<cWorldManager> _instance;
public:
	static std::shared_ptr<cWorldManager> Get();

	cWorldManager();
	~cWorldManager();

	void CreateWorld();
private:

};