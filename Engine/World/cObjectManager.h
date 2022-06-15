#pragma once

#include <vector>
#include <memory>

#include "Cube.h"

class cObjectManager
{
public:
	cObjectManager();
	~cObjectManager();

	size_t GetNumberOfObjects() const;

	std::shared_ptr<Object> GetObject(const unsigned int& index) const;
	template <class T>
	std::shared_ptr<T> CreateObject();
private:
	std::vector<std::shared_ptr<Object>> _objects = {};
};