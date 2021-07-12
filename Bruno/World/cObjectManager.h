#pragma once

#include <vector>
#include <memory>

#include "Object.h"
#include "Cube.h"

using ObjectList_t	= std::vector<Object*>;

class cObjectManager
{
public:
	cObjectManager();
	~cObjectManager();

	size_t GetNumberOfObjects() const;

	Object* GetObject(const unsigned int& index) const;
	template <class T>
	T* CreateObject(const glm::vec3& position = {});
private:
	ObjectList_t _objects = {};
};