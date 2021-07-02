#include "Graphics/Manager.h"

int main()
{
	// Grab instance of our graphics manager
	auto pGM = cGraphicsManager::Get();

	// Create window and check if sucessful
	if (!pGM->CreateWindow())
		return -1;

	// Initalize our shaders
	Shader shaders("default.vert", "default.frag");

	// Vertex data
	GLfloat vertices[] = {
		 0.5f,  0.5f, 0.0f,		// top right
		 0.5f, -0.5f, 0.0f,		// bottom right
		-0.5f, -0.5f, 0.0f,		// bottom left
		-0.5f,  0.5f, 0.0f		// top left 
	};
	GLuint indices[] = {		// note that we start from 0!
		0, 1, 3,				// first triangle
		1, 2, 3					// second triangle
	};

	// VBO data?
	VAO vao;
	vao.Bind();

	// Vertex data
	VBO vbo(vertices, sizeof(vertices), GL_STATIC_DRAW);

	EBO ebo(indices, sizeof(indices), GL_STATIC_DRAW);

	// Position attribute
	vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)(0));

	// Prevent modification
	vao.Unbind();

	/************************************************************************
	*************************************************************************
	************************************************************************/
	//draw in wireframe polygons.
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Our "render loop" used for our drawing purposes and to prevent our application from closing immediately
	while (!glfwWindowShouldClose(pGM->GetWindowHandle()))
	{
		// Process inputs from our window
		pGM->ProcessInput();

		/***********************************************************************
		****					RENDERING DONE HERE							****
		***********************************************************************/

		// Color of background
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);					// STATE-SETTING FUNCTION
		// Cleaning up the back buffer and depth buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// STATE-USING FUNCTION

		// Activate our vertex and fragment shader code
		shaders.Activate();
		// Use our vertex buffer object
		vao.Bind();
		// Draw
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		/************************************************************************
		*************************************************************************
		************************************************************************/

		// Swaping the front for the back buffer
		glfwSwapBuffers(pGM->GetWindowHandle());

		// Handles events (inputs, window state, callbacks)
		glfwPollEvents();
	}

	// Cleanup!
	vao.Delete();
	vbo.Delete();
	ebo.Delete();
	shaders.Delete();
	
	return 0;
}