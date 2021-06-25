#include "Graphics/Manager.h"

int main()
{
	// Grab instance of our graphics manager
	auto pGM = cGraphicsManager::Get();

	// Create window and check if sucessful
	if (!pGM->CreateWindow())
		return -1;

	// Main while loop
	pGM->LogicLoop();

	return 0;
}