#include "Bruno/Bruno.h"

int main()
{
	auto engine = cBrunoEngine::GetEngine();
	auto window = engine->GetWindowManager();
	auto world = engine->GetWorldManager();

	if (!window->CreateWindow())
	{
		// TODO: ERROR MSG
		return -1;
	}

	// Main game loop
	while (!window->ShouldClose())
	{
		// Calculate deltaTime
		window->CalculateDeltaTime();

		// Process keyboard input
		window->ProcessEvents();

		// Render
		window->Render();

		// Handles events (inputs, window state, callbacks)
		window->ProcessEvents();
	}
}