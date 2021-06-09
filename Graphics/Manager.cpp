#include "Manager.h"

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

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

	// Call our render stuff
	{
		// Shader start-up
		InitalizeShaders();

		// Buffer start-up
		InitalizeBuffers();

		//				(x,y)  top right		
		// bottom left  (0,0)
		glViewport(0, 0, _windowSize.x, _windowSize.y);

		// Color of background
		glClearColor(0.90f, 0.50f, 0.50f, 1.0f);

		// Cleaning up the back buffer and assigning a new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap the front with our new back buffer.
		glfwSwapBuffers(_pWindow);
	}

	// Sucess!
	return true;
}

void cGraphicsManager::Loop()
{
	while (!glfwWindowShouldClose(_pWindow))
	{
		// Color of background
		glClearColor(0.90f, 0.50f, 0.50f, 1.0f);
		// Cleaning up the back buffer and assigning a new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(_shaderProgram);
		glBindVertexArray(_VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(_pWindow);

		// Handles GLFW events
		glfwPollEvents();
	}
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
	// Cleanup buffers and vertex arrays
	glDeleteVertexArrays(1, &_VAO);
	glDeleteBuffers(1, &_VBO);
	glDeleteProgram(_shaderProgram);

	// Uninitalize GLFW
	glfwDestroyWindow(_pWindow);
	glfwTerminate();

	// Cleanup
	if (_pGM != nullptr)
		_pGM = nullptr;
}

std::shared_ptr<cGraphicsManager> cGraphicsManager::Get()
{
	// Create only once instance of our graphics manager
	if (_pGM == nullptr)
		_pGM = std::make_shared<cGraphicsManager>();

	// Return instance of our GM
	return _pGM;
}

void cGraphicsManager::InitalizeShaders()
{
	// Create vertex shader w/ source
	_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(_vertexShader);

	// Create fragment shader w/ source
	_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(_fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(_fragmentShader);

	// Create and link shader program w/ shaders
	_shaderProgram = glCreateProgram();
	glAttachShader(_shaderProgram, _vertexShader);
	glAttachShader(_shaderProgram, _fragmentShader);
	glLinkProgram(_shaderProgram);

	// Clean up shaders since they're already loaded into shader program
	glDeleteShader(_vertexShader);
	glDeleteShader(_fragmentShader);
}

void cGraphicsManager::InitalizeBuffers()
{
	// Vertices coordinates
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
	};

	// Generate (vertex) arrays and buffers to VAO, VBO
	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);

	// Bind (vertex) arrays and buffers to VAO, VBO
	glBindVertexArray(_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);

	// Introducing vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Configure the vertex attribute so that OpenGL knows how to read the VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)(0));
	// Enable the vertex attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(0);

	// Binding the VAO and VBO to prevent accidental modification.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
