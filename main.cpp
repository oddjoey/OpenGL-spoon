#include "Graphics/Manager.h"

int main()
{
	// Grab instance of our graphics manager
	auto pGM = cGraphicsManager::Get();

	// Create window and check if sucessful
	if (!pGM->CreateWindow())
		return -1;

	/************************************************************************
	*************************************************************************
	************************************************************************/

	// Initalize our shaders
	Shader shaders("default.vert", "default.frag");

	// Vertex data
	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f
	};

	// Scene data
	VAO vao;
	vao.Bind();

	// Object data
	VBO vbo(vertices, sizeof(vertices), GL_STATIC_DRAW);
	//EBO ebo(indices, sizeof(indices), GL_STATIC_DRAW);

	// Position attribute
	vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(0));
	// Color attribute
	vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 3));

	// Prevent modification
	vao.Unbind();

	/************************************************************************
	*************************************************************************
	************************************************************************/

	Camera* camera = pGM->CreateCamera();
	camera->SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));
	camera->SetFront(glm::vec3(0.0f, 0.0f, -1.0f));
	camera->SetUp(glm::vec3(0.0f, 1.0f, 0.0f));
	camera->SetSpeed(3.0f);

	/************************************************************************
	*************************************************************************
	************************************************************************/

	// draw wireframe polygons.
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// Depth testing to fix overlaping
	glEnable(GL_DEPTH_TEST);
	// Activate our vertex and fragment shader code
	shaders.Activate();

	// Our "render loop" used for our drawing purposes and to prevent our application from closing immediately
	while (!glfwWindowShouldClose(pGM->GetWindowHandle()))
	{
		double currentFrame = glfwGetTime();
		pGM->SetDeltaTime(currentFrame - pGM->GetLastFrame());
		pGM->SetLastFrame(currentFrame);

		// Process inputs from our window
		pGM->ProcessInput();

		/************************************************************************
		****							GOING 3D							 ****
		************************************************************************/

		/* MODEL MATRIX - Object orientation */
		glm::mat4 model = glm::mat4(1.0f);	// Identity matrix
		model = glm::rotate(model, (GLfloat)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

		/* VIEW MATRIX - Camera orientation */
		glm::mat4 view = glm::mat4(1.0f);
		// Moving model forwards to simulate camera moving back
		view = glm::lookAt(camera->GetPosition(), camera->GetPosition() + camera->GetFront(), camera->GetUp());

		/* PROJECTION MATRIX - Perspective */
		// Perspective projection, 45 fov, near clip 0.1, far clip 100
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (GLfloat)(pGM->GetScreenSize().x / pGM->GetScreenSize().y), 0.1f, 100.0f);

		/***********************************************************************
		****					RENDERING DONE HERE							****
		***********************************************************************/

		// Color of background
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);													// STATE-SETTING FUNCTION
		// Cleaning up the back buffer and depth buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);										// STATE-USING FUNCTION

		// Sending model matrix to shaders
		GLuint uniModelMat = glGetUniformLocation(shaders.GetID(), "model");
		glUniformMatrix4fv(uniModelMat, 1, GL_FALSE, glm::value_ptr(model));

		// Sending view matrix to shaders
		GLuint uniViewMat = glGetUniformLocation(shaders.GetID(), "view");
		glUniformMatrix4fv(uniViewMat, 1, GL_FALSE, glm::value_ptr(view));

		// Sending projection matrix to shaders
		GLuint uniProjectionMat = glGetUniformLocation(shaders.GetID(), "projection");
		glUniformMatrix4fv(uniProjectionMat, 1, GL_FALSE, glm::value_ptr(projection));

		// Use our vertex buffer object
		vao.Bind();
		// Draw
		glDrawArrays(GL_TRIANGLES, 0, 36);


		/************************************************************************
		*************************************************************************
		************************************************************************/

		// Swaping the front for the back buffer
		glfwSwapBuffers(pGM->GetWindowHandle());

		// Handles events (inputs, window state, callbacks)
		glfwPollEvents();
	}

	return 0;
}