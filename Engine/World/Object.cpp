#include "Object.h"

Object::Object(const size_t& index)
{
	_index = index;
}

Object::~Object()
{
}

size_t Object::GetIndex() const
{
	return _index;
}

glm::vec3 Object::GetPosition() const
{
	return _position;
}

Object* Object::SetPosition(const glm::vec3& newPosition)
{
	_position = newPosition;
	return this;
}

std::shared_ptr<Model> Object::GetModel() const
{
	return _model;
}

Object* Object::SetModel(const std::shared_ptr<Model>& model)
{
	if (model != nullptr)
		_model = model;

	return this;
}
