#include "SimulationGame.h"
#include "SimException.h"
#include <iostream>

int main()
{
	// Declare our Game Object
	auto gameInstance = new SimulationGame();

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
