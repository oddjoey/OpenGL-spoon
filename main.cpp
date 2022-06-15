#include "Engine/Engine.h"

int main()
{
	// Initialize engine and its interfaces
	auto engine				= cEngine::GetEngine();
	auto windowManager		= engine->GetWindowManager();
	auto graphicsManager	= windowManager->GetGraphicsManager();
	auto modelManager		= graphicsManager->GetModelManager();
	auto worldManager		= engine->GetWorldManager();
	auto objectManager		= worldManager->GetObjectManager();

	// Create window
	if (!windowManager->CreateWindow())
		return -100;

	// Create shaders
	auto shader = graphicsManager->CreateShader("default.vert", "default.frag");
	shader->Activate();

	// Create box model
	std::vector<GLfloat>	vertices		= {
			-0.5f, 0.5f, 0.f,		//v0
			-0.5f, -0.5f, 0.f,		//v1
			0.5f, -0.5f, 0.f,		//v2
			0.5f, 0.5f, 0.f,		//v3
	};
	std::vector<GLuint>		indices			= {
				0,1,3,				//top left triangle (v0, v1, v3)
				3,1,2,				//bottom right triangle (v3, v1, v2)
	};
	std::vector<GLfloat>	textureCoords	= {
		1, 1,
		1, 0,
		0, 0,
		0, 1
	};
	auto model = modelManager->CreateModel(vertices, textureCoords, indices);
	
	// Create texture for model
	auto texture = modelManager->CreateTexture("pop_cat.png");
	model->SetTexture(texture);

	// Create object and assign model to object
	auto cube = objectManager->CreateObject<Cube>();
	cube->SetModel(model);

	// Main game loop
	while (!windowManager->ShouldClose())
	{
		// Calculate deltaTime
		windowManager->CalculateDeltaTime();

		// Process keyboard input
		windowManager->ProcessKeyboard();

		// Render
		windowManager->Render();

		// Handles events (inputs, window state, callbacks)
		windowManager->ProcessEvents();
	}
}