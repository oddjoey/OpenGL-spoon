#include "Camera.h"

Camera* Camera::SetPosition(glm::vec3 newPosition)
{
	_position = newPosition;
	return this;
}

glm::vec3 Camera::GetPosition() const
{
	return _position;
}

Camera* Camera::SetFront(glm::vec3 newFront)
{
	_front = newFront;
	return this;
}

glm::vec3 Camera::GetFront() const
{
	return _front;
}

Camera* Camera::SetUp(glm::vec3 newUp)
{
	_up = newUp;
	return this;
}

glm::vec3 Camera::GetUp() const
{
	return _up;
}

Camera* Camera::SetSpeed(GLfloat newSpeed)
{
	_speed = newSpeed;
	return this;
}

GLfloat Camera::GetSpeed() const
{
	return _speed;
}

glm::vec2 Camera::GetMousePositon() const
{
	return _mousePos;
}

Camera* Camera::SetMousePosition(glm::vec2 newMouse)
{
	_mousePos = newMouse;
	return this;
}

GLfloat Camera::GetSensitivity() const
{
	return _sensitivity;
}

Camera* Camera::SetSensitivity(GLfloat newSensitivity)
{
	_sensitivity = newSensitivity;
	return this;
}

//Camera* Camera::SetViewAngles(glm::vec2 newViewAngles)
//{
//	_viewAngles = newViewAngles;
//
//	glm::vec3 direction;
//	direction.x = cos(glm::radians(newViewAngles.x)) * cos(glm::radians(newViewAngles.y));
//	direction.y = sin(glm::radians(newViewAngles.y));
//	direction.z = sin(glm::radians(newViewAngles.x)) * cos(glm::radians(newViewAngles.y));
//
//	_front = glm::normalize(direction);
//
//	return this;
//}
//
//glm::vec2 Camera::GetViewAngles() const
//{
//	return _viewAngles;
//}

Camera::Camera()
{
}

Camera::~Camera()
{
}
