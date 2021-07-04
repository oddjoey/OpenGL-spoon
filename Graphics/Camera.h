#pragma once

#include <glad/glad.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

class Camera
{
public:
	Camera* SetPosition(glm::vec3 newPosition);
	glm::vec3 GetPosition();
	
	Camera* SetFront(glm::vec3 newFront);
	glm::vec3 GetFront();
		
	Camera* SetUp(glm::vec3 newUp);
	glm::vec3 GetUp();

	Camera* SetSpeed(GLfloat newSpeed);
	GLfloat GetSpeed();

	Camera();
	~Camera();
private:
	glm::vec3 _position = glm::vec3(0.0f);
	glm::vec3 _front	= glm::vec3(0.0f);
	glm::vec3 _up		= glm::vec3(0.0f);
	GLfloat _speed		= 0.0f;
};

