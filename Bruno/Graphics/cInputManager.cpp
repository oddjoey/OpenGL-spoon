#include "cInputManager.h"

glm::vec2 cInputManager::getWASD() const
{
	return _wasd;
}

void cInputManager::setMousePosition(const glm::vec2& newMousePosition)
{
	_mousePosition = newMousePosition;
}

glm::vec2 cInputManager::getMousePosition() const
{
	return _mousePosition;
}

void cInputManager::ProcessKeyboard(GLFWwindow* window)
{


	//double newCameraSpeed = _camera->GetSpeed() * _deltaTime;

	//auto front = _camera->GetFront();
	//front.y = 0;

	//if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	//	_camera->SetPosition(_camera->GetPosition() + (GLfloat)(newCameraSpeed)*front);
	//if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	//	_camera->SetPosition(_camera->GetPosition() - (GLfloat)(newCameraSpeed)*front);
	//if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	//	_camera->SetPosition(_camera->GetPosition() - glm::normalize(glm::cross(front, _camera->GetUp())) * (GLfloat)(newCameraSpeed));
	//if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	//	_camera->SetPosition(_camera->GetPosition() + glm::normalize(glm::cross(front, _camera->GetUp())) * (GLfloat)(newCameraSpeed));

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	_wasd = { 0.0f, 0.0f };

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		_wasd.y += 1.0f;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		_wasd.y -= 1.0f;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		_wasd.x -= 1.0f;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		_wasd.x += 1.0f;

}

cInputManager::cInputManager()
{
}

cInputManager::~cInputManager()
{
}
