#include "Bruno/Bruno.h"

int main()
{
	auto engine = cBrunoEngine::GetEngine();
	auto windowManager = engine->GetWindowManager();
	auto worldManager = engine->GetWorldManager();
	auto objectManager = worldManager->GetObjectManager();

	if (!windowManager->CreateWindow())
	{
		// TODO: ERROR MSG
		return -1;
	}

	auto object = objectManager->CreateObject<Object>();
	auto cube	= objectManager->CreateObject<Cube>();

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