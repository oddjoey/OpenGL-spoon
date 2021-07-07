#pragma once

#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

class cInputManager
{
public:
	void setMousePosition(glm::vec2 newMousePosition);
	glm::vec2 getMousePosition() const;

	glm::vec2 getWASD() const;

	void ProcessKeyboard(GLFWwindow* window);

	cInputManager();
	~cInputManager();
private:
	glm::vec2 _wasd				= {};
	glm::vec2 _mousePosition	= {};
};