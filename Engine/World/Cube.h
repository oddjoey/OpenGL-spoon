#pragma once

#include "Object.h"

class Cube : public Object
{
	Cube() = delete;
public:
	Cube(const size_t& index);
	~Cube();
};

