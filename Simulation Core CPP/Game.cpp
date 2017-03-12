#include "Game.h"
#include "SimException.h"
#include <iostream>

bool sim::Game::InitializeGame()
{
	// Add all civilizations to the game 
	_civilizations["Egypt"] = new Civilization("Egypt");
	_civilizations["Iraq"] = new Civilization("Iraq");

	// Initialize all Civilizations of the game
	for each (auto& civ in _civilizations)
	{
		if (!civ.second->Initialize())
			throw SimException("Cannot initialize civilization " + civ.first);
	}

	return true;
}

void sim::Game::RunGame()
{
	// Do the game loop
	while (_isGameStarted)
	{		
		// Compute the elapsed seconds
		_gameClock.Start();

		// Update all civilizatoins of the game
		for each (auto& civ in _civilizations)
		{
			civ.second->Update(_gameClock.GetElapsedGameTime());
		}
	}
}

void sim::Game::FinalizeGame()
{
	_isGameStarted = false;

	// Finalize the civilizations of the game
	for each (auto& civ in _civilizations)
	{
		civ.second->Finalize();
		delete civ.second;
	}
}
