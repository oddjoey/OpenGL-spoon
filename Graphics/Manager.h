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

	static std::shared_ptr<cGraphicsManager> Get();
private:

	GLFWwindow*		_pWindow							= nullptr;
	Vector2<int>	_windowSize							= {};
	std::string		_windowTitle						= "";

	static std::shared_ptr<cGraphicsManager> _pGM;
};