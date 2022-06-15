#pragma once

#include <iostream>
#include <glm/glm/glm.hpp>

#include "../Graphics/Model.h"

class Object
{
	Object() = delete;
public:
	Object(const size_t& index);
	~Object();

	size_t GetIndex() const;

	glm::vec3 GetPosition() const;
	Object* SetPosition(const glm::vec3& newPosition);

	std::shared_ptr<Model> GetModel() const;
	Object* SetModel(const std::shared_ptr<Model>& model);

private:
	glm::vec3 _position = {};
	size_t _index = 0;
protected:
	std::shared_ptr<Model> _model = nullptr;
};

