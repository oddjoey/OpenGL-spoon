#include "Manager.h"

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
		return false;
	}

	// HMM..
	glfwMakeContextCurrent(_pWindow);

	// Load GLAD to config OpenGL
	gladLoadGL();

	// Sucess!
	return true;
}

void cGraphicsManager::LogicLoop()
{
	//				(x,y)  top right		
	// bottom left  (0,0)
	glViewport(0, 0, _windowSize.x, _windowSize.y);

	// Vertices coordinates
	GLfloat vertices[] =
	{ //               COORDINATES                  /     COLORS           //
		-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
		 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
		 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
		-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
		 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
		 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
	};

	// Indices for vertices order
	GLuint indices[] =
	{
		0, 3, 5, // Lower left triangle
		3, 2, 4, // Lower right triangle
		5, 4, 1 // Upper triangle
	};

	/*
	*	GENERATION OF [SHADERS, VAO, VBO, EBO] FOR DRAWING SHAPES
	*/

	// Generating shaders using default.vert & default.frag
	Shaders shaders("default.vert", "default.frag");

	// Vertex Array Object
	VAO VAO1;
	VAO1.Bind();

	// Vertex Buffer Object (for vertices)
	VBO VBO1(vertices, sizeof(vertices));

	// Element Buffer Object (for indices)
	EBO EBO1(indices, sizeof(indices));

	// XYZ Component of vertex
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(0));
	// RGB Component of vertex
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

	// Unbinding to prevent modification
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	/*
	* 
	*/

	while (!glfwWindowShouldClose(_pWindow))
	{
		// Color of background
		glClearColor(0.90f, 0.50f, 0.50f, 1.0f);
		// Cleaning up the back buffer and assigning a new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		shaders.Activate();
		VAO1.Bind();

		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(_pWindow);

		// Handles GLFW events
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaders.Delete();
}

Vector2<int> cGraphicsManager::GetScreenSize() const
{
	return _windowSize;
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