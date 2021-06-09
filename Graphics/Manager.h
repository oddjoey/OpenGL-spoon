#pragma once

#include "..\Shaders.h"

template <class T>
struct Vector2
{
	T x, y;
};

class cGraphicsManager
{
public:
	bool CreateWindow(const int& x = 800, const int& y = 800, const std::string& title = "OpenGL-kowy");
	void Loop();

	Vector2<int> GetScreenSize() const;

	cGraphicsManager();
	~cGraphicsManager();

	static std::shared_ptr<cGraphicsManager> Get();
private:
	void InitalizeShaders();
	void InitalizeBuffers();

	GLuint			_VAO, _VBO, _EBO					= NULL;
	GLuint			_vertexShader, _fragmentShader		= NULL;
	GLuint			_shaderProgram						= NULL;
	GLFWwindow*		_pWindow							= nullptr;
	Vector2<int>	_windowSize							= {};
	std::string		_windowTitle						= "";

	static std::shared_ptr<cGraphicsManager> _pGM;
};