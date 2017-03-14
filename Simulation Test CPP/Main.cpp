#include <Simulation Core.h>
#include <memory>
#include <iostream>

int main()
{
	// Declare our Game Object
	auto gameInstance = sim::Game::getInstance();

	try 
	{
		// Initialize the Game
		if (!gameInstance->initializeGame())
			throw sim::SimException("Cannot initialize the game");

		// Run the Game loop
		gameInstance->runGame();

		// Finalize the Game
		gameInstance->finalizeGame();
	}
	catch (sim::SimException& exp)
	{
		std::cerr << exp.getMessage() << std::endl;
	}
	
	delete gameInstance;

	return 0;
}
