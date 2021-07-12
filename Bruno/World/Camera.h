#pragma once

#include <memory>
#include <glad/glad.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

class Camera
{
public:
	Camera* SetPosition(glm::vec3 newPosition);
	glm::vec3 GetPosition() const;
	
	Camera* SetFront(glm::vec3 newFront);
	glm::vec3 GetFront() const;
		
	Camera* SetUp(glm::vec3 newUp);
	glm::vec3 GetUp() const;

	Camera* SetSpeed(GLfloat newSpeed);
	GLfloat GetSpeed() const;

	Camera* SetMousePosition(glm::vec2 newMouse);
	glm::vec2 GetMousePositon() const;

	Camera* SetSensitivity(GLfloat newSensitivity);
	GLfloat GetSensitivity() const;

	Camera();
	~Camera();
private:
	glm::vec3 _position		= glm::vec3(0.0f);
	glm::vec3 _front		= glm::vec3(0.0f);
	glm::vec3 _up			= glm::vec3(0.0f);
	GLfloat _speed			= 0.0f;
	glm::vec2 _mousePos		= {};
	GLfloat _sensitivity	= 0.0f;
	glm::vec2 _viewAngles	= {};
};

