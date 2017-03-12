#include <Simulation Core.h>
#include <memory>
#include <iostream>

int main()
{
	// Declare our Game Object
	auto gameInstance = sim::Game::GetInstance();

	try 
	{
		// Initialize the Game
		if (!gameInstance->InitializeGame())
			throw sim::SimException("Cannot initialize the game");

		// Run the Game loop
		gameInstance->RunGame();

		// Finalize the Game
		gameInstance->FinalizeGame();
	}
	catch (sim::SimException& exp)
	{
		std::cerr << exp.GetMessage() << std::endl;
	}
	
	delete gameInstance;

	return 0;
}
