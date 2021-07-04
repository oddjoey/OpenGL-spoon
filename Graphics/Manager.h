#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Texture.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Camera.h"

template <class T>
struct Vector2
{
	T x, y;
};

// Called by OpenGL when our window gets resized, also called when the window is first displayed.
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class cGraphicsManager
{
public:
	bool CreateWindow(const int& x = 800, const int& y = 800, const std::string& title = "OpenGL-kowy");
	void ProcessInput();

	Vector2<int> GetScreenSize() const;
	GLFWwindow* GetWindowHandle() const;

	cGraphicsManager();
	~cGraphicsManager();

	void SetDeltaTime(double newDelta);
	double GetDeltaTime();

	void SetLastFrame(double newLastFrame);
	double GetLastFrame();

	Camera* CreateCamera();
	Camera* GetCamera();

	static std::shared_ptr<cGraphicsManager> Get();
private:

	GLFWwindow*				_window								= nullptr;
	Vector2<int>			_windowSize							= {};
	std::string				_windowTitle						= "";
	std::shared_ptr<Camera>	_camera								= nullptr;
	double					_deltaTime							= 0.0f;
	double					_lastFrame							= 0.0f;

	static std::shared_ptr<cGraphicsManager> _pGM;
};