#pragma once

#include <iostream>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>

#include "cGraphicsManager.h"
#include "cInputManager.h"
#include "..\World\cWorldManager.h"

// Mouse positon callback
void ProcessMouseCallback(GLFWwindow* window, double xpos, double ypos);
// Called by OpenGL when our window gets resized, also called when the window is first displayed.
void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

enum class eSize
{
	FULL = 0,
	HALF = 1
};

class cWindowManager
{
	static std::shared_ptr<cWindowManager> _instance;
public:
	static std::shared_ptr<cWindowManager> Get();
	std::shared_ptr<cGraphicsManager> GetGraphicsManager();

	friend void ProcessMouseCallback(GLFWwindow* window, double xpos, double ypos);

	double GetDeltaTime() const;
	glm::vec2 GetScreenSize(const eSize& type) const;
	GLFWwindow* GetWindowHandle() const;

	bool ShouldClose() const;

	void LockCursor();
	void UnlockCursor();
	void HideCursor();

	bool CreateWindow(const int& x = 800, const int& y = 800, const std::string& title = "OpenGL-kowy");

	void CalculateDeltaTime();
	void Render();
	void ProcessKeyboard();
	void ProcessEvents();

	cWindowManager();
	~cWindowManager();
private:
	GLFWwindow*				_window								= nullptr;
	glm::vec2				_windowSize							= {};
	std::string				_windowTitle						= "";
	double					_deltaTime							= 0.0f;
	double					_lastTime							= 0.0f;

	std::shared_ptr<cInputManager> _inputManager				= nullptr;
};