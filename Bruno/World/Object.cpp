#include "Object.h"

Object::Object()
{

}

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
