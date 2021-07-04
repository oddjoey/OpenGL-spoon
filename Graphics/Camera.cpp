#include "Camera.h"

Camera* Camera::SetPosition(glm::vec3 newPosition)
{
	_position = newPosition;
	return this;
}

glm::vec3 Camera::GetPosition()
{
	return _position;
}

Camera* Camera::SetFront(glm::vec3 newFront)
{
	_front = newFront;
	return this;
}

glm::vec3 Camera::GetFront()
{
	return _front;
}

Camera* Camera::SetUp(glm::vec3 newUp)
{
	_up = newUp;
	return this;
}

glm::vec3 Camera::GetUp()
{
	return _up;
}

Camera* Camera::SetSpeed(GLfloat newSpeed)
{
	_speed = newSpeed;
	return this;
}

GLfloat Camera::GetSpeed()
{
	return _speed;
}

Camera::Camera()
{
}

Camera::~Camera()
{
}
