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

	//				(x,y)  top right		
	// bottom left  (0,0)
	glViewport(0, 0, _windowSize.x, _windowSize.y);

	// Sucess!
	return true;
}

void cGraphicsManager::LogicLoop()
{
	// Vertices coordinates
	GLfloat vertices[] =
	{ //     COORDINATES     /        COLORS      /   TexCoord  //
		-0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower left corner
		-0.5f,  0.5f, 0.0f,     0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper left corner
		 0.5f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
		 0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
	};

	// Indices for vertices order
	GLuint indices[] =
	{
		0, 2, 1, // Upper triangle
		0, 3, 2 // Lower triangle
	};

	/***********************************************************************
	****	GENERATION OF [SHADERS, VAO, VBO, EBO] FOR DRAWING SHAPES	****
	***********************************************************************/

	// Generating shaders using default.vert & default.frag
	Shader shaders("default.vert", "default.frag");

	// Vertex Array Object
	VAO VAO1;
	VAO1.Bind();

	// Vertex Buffer Object (for vertices)
	VBO VBO1(vertices, sizeof(vertices));

	// Element Buffer Object (for indices)
	EBO EBO1(indices, sizeof(indices));

	// XYZ Component of vertex
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(0));
	// RGB Component of vertex
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	// Texture Component of vertex
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));

	// Unbinding to prevent modification
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	/************************************************************************
	************************************************************************* 
	************************************************************************/

	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaders.GetID(), "scale");

	Texture popCat("pop_cat.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	popCat.SetUniform(shaders, "tex0", 0);

	while (!glfwWindowShouldClose(_pWindow))
	{
		// Color of background
		glClearColor(0.90f, 0.50f, 0.50f, 1.0f);
		// Cleaning up the back buffer and assigning a new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		shaders.Activate();

		// Assigns a value to the uniform; NOTE: Must always be done after activating shaders
		glUniform1f(uniID, 0.0f);

		popCat.Bind();

		VAO1.Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(_pWindow);

		// Handles GLFW events
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	popCat.Delete();
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