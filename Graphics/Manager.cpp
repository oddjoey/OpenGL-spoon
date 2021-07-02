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
	_pWindow = glfwCreateWindow(x, y, title.c_str(), NULL, NULL);

	if (_pWindow == nullptr)
	{
		std::cout << "Failed to create GLFW window!\n";
		glfwTerminate();
		return false;
	}

	// Make context of our window the main context on the current thread
	glfwMakeContextCurrent(_pWindow);

	// Register our callback function for window resizing purposes
	glfwSetFramebufferSizeCallback(_pWindow, framebuffer_size_callback);

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
	//if (glfwGetKey(_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	//	glfwSetWindowShouldClose(_pWindow, true);
}

Vector2<int> cGraphicsManager::GetScreenSize() const
{
	return _windowSize;
}

GLFWwindow* cGraphicsManager::GetWindowHandle() const
{
	return _pWindow;
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
	glfwDestroyWindow(_pWindow);
	glfwTerminate();

	// Cleanup
	if (_pGM != nullptr)
		_pGM = nullptr;
}

std::shared_ptr<cGraphicsManager> cGraphicsManager::Get()
{
	// Create only one instance of our graphics manager
	if (_pGM == nullptr)
		_pGM = std::make_shared<cGraphicsManager>();

	// Return instance of our GM
	return _pGM;
}