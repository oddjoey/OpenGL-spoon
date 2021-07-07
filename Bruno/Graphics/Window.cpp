#include "Window.h"

std::shared_ptr<cWindowManager> cWindowManager::_instance = nullptr;

void ProcessMouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	//static bool bFirst = true;
	//if (bFirst)
	//{
	//	cBrunoEngine::GetGraphicsEngine()->GetCamera()->SetMousePosition(glm::vec2(xpos, ypos));
	//	bFirst = !bFirst;
	//}


	//auto pGM = cBrunoEngine::GetGraphicsEngine();
	//auto camera = pGM->GetCamera();

	//double xOffset = xpos - camera->GetMousePositon().x;
	//double yOffset = camera->GetMousePositon().y - ypos;

	//camera->SetMousePosition(glm::vec2(xpos, ypos));

	//xOffset *= camera->GetSensitivity();
	//yOffset *= camera->GetSensitivity();

	//glm::vec2 newViewAngles = camera->GetViewAngles();
	//newViewAngles += glm::vec2(xOffset, yOffset);

	//if (newViewAngles.y > 89.0f)
	//	newViewAngles.y = 89.0f;

	//if (newViewAngles.y < -89.0f)
	//	newViewAngles.y = -89.0f;

	//camera->SetViewAngles(newViewAngles);

	cWindowManager::Get()->_inputManager->setMousePosition({ xpos, ypos });
}

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void cWindowManager::LockCursor()
{
	// Hides and grabs cursor
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void cWindowManager::UnlockCursor()
{
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void cWindowManager::HideCursor()
{
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

bool cWindowManager::CreateWindow(const int& x, const int& y, const std::string& title)
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
	glfwSetFramebufferSizeCallback(_window, FramebufferSizeCallback);

	// Initalize our input manager for mouse and keyboard interception
	_inputManager = std::make_shared<cInputManager>();

	// Registers function for mouse input
	glfwSetCursorPosCallback(_window, ProcessMouseCallback);

	// Load GLAD to config OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD!\n";
		return false;
	}

	// Sucess!
	return true;
}

void cWindowManager::CalculateDeltaTime()
{
	double currentTime = glfwGetTime();
	_deltaTime = currentTime - _lastTime;
	_lastTime = currentTime;
}

void cWindowManager::Render()
{
	// Swaping the front for the back buffer
	glfwSwapBuffers(_window);
}

void cWindowManager::ProcessKeyboard()
{
	_inputManager->ProcessKeyboard(_window);
}

void cWindowManager::ProcessEvents()
{
	glfwPollEvents();
}

glm::vec2 cWindowManager::GetScreenSize(eSize type) const
{
	if (type == eSize::FULL)
		return _windowSize;
	else
		return glm::vec2(_windowSize.x / 2, _windowSize.y / 2);
}

GLFWwindow* cWindowManager::GetWindowHandle() const
{
	return _window;
}

bool cWindowManager::ShouldClose() const
{
	return glfwWindowShouldClose(_window);
}

cWindowManager::cWindowManager()
{
	// Initalize GLFW
	glfwInit();
	// Tell GLFW that we're using version 3.3 of OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core profile includes OpenGL's "modern functions"
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

cWindowManager::~cWindowManager()
{
	// Uninitalize GLFW
	glfwDestroyWindow(_window);
	glfwTerminate();
}

std::shared_ptr<cWindowManager> cWindowManager::Get()
{
	if (_instance == nullptr)
		_instance = std::make_shared<cWindowManager>();

	return _instance;
}

double cWindowManager::GetDeltaTime()
{
	return _deltaTime;
}