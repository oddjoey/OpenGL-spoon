#include "Manager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

std::shared_ptr<cGraphicsManager> cGraphicsManager::_pGM = nullptr;

bool cGraphicsManager::CreateWindow(const int& x, const int& y, const std::string& title)
{
	// Set settings up for GLFW and our GM
	_windowSize = { x , y };
	_windowTitle = title;
	_window = glfwCreateWindow(x, y, title.c_str(), NULL, NULL);

	if (_window == nullptr)
	{
		std::cout << "Failed to create GLFW window!\n";
		glfwTerminate();
		return false;
	}

	// Make context of our window the main context on the current thread
	glfwMakeContextCurrent(_window);

	// Register our callback function for window resizing purposes
	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

	// Load GLAD to config OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD!\n";
		return false;
	}

	// Sucess!
	return true;
}

void cGraphicsManager::ProcessInput()
{
	double newCameraSpeed = _camera->GetSpeed() * _deltaTime;

	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
		_camera->SetPosition(_camera->GetPosition() + (GLfloat)(newCameraSpeed) * _camera->GetFront());
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS)
		_camera->SetPosition(_camera->GetPosition() - (GLfloat)(newCameraSpeed)* _camera->GetFront());
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS)
		_camera->SetPosition(_camera->GetPosition() - glm::normalize(glm::cross(_camera->GetFront(), _camera->GetUp())) * (GLfloat)(newCameraSpeed));
	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS)
		_camera->SetPosition(_camera->GetPosition() + glm::normalize(glm::cross(_camera->GetFront(), _camera->GetUp())) * (GLfloat)(newCameraSpeed));
}

Vector2<int> cGraphicsManager::GetScreenSize() const
{
	return _windowSize;
}

GLFWwindow* cGraphicsManager::GetWindowHandle() const
{
	return _window;
}

cGraphicsManager::cGraphicsManager()
{
	// Initalize GLFW
	glfwInit();
	// Tell GLFW that we're using version 3.3 of OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core profile includes OpenGL's "modern functions"
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

cGraphicsManager::~cGraphicsManager()
{
	// Uninitalize GLFW
	glfwDestroyWindow(_window);
	glfwTerminate();

	// Cleanup
	if (_pGM != nullptr)
		_pGM = nullptr;
}

void cGraphicsManager::SetDeltaTime(double newDelta)
{
	_deltaTime = newDelta;
}

double cGraphicsManager::GetDeltaTime()
{
	return _deltaTime;
}

void cGraphicsManager::SetLastFrame(double newLastFrame)
{
	_lastFrame = newLastFrame;
}

double cGraphicsManager::GetLastFrame()
{
	return _lastFrame;
}

Camera* cGraphicsManager::CreateCamera()
{
	if (_camera == nullptr)
		_camera = std::make_shared<Camera>();

	return _camera.get();
}

Camera* cGraphicsManager::GetCamera()
{
	return _camera.get();
}

std::shared_ptr<cGraphicsManager> cGraphicsManager::Get()
{
	// Create only one instance of our graphics manager
	if (_pGM == nullptr)
		_pGM = std::make_shared<cGraphicsManager>();

	// Return instance of our GM
	return _pGM;
}