#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

class Object
{
public:
	Object();
	Object(const size_t& index);
	~Object();

	size_t GetIndex() const;

	glm::vec3 GetPosition() const;
	Object* SetPosition(const glm::vec3& newPosition);
private:
	glm::vec3 _position = {};
	size_t _index = 0;
protected:
	GLfloat* _vertices = nullptr;
};

