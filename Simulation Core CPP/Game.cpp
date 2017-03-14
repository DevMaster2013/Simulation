#include "Game.h"
#include "SimException.h"
#include "NamesFileResource.h"
#include <iostream>

bool sim::Game::initializeGame()
{
	// Load Game Resources
	_resManager = ResourceManager::getInstance();
	_resManager->loadAllResources();

	if (!loadCivilizations())
		throw SimException("Cannot initialize civilizations");

	return true;
}

void sim::Game::runGame()
{
	// Do the game loop
	while (_isGameStarted)
	{		
		// Compute the elapsed seconds
		_gameClock.start();

		// Update all civilizatoins of the game
		for each (auto& civ in _civilizations)
		{
			civ.second->update(_gameClock.getElapsedGameTime());
		}
	}
}

void sim::Game::finalizeGame()
{
	_isGameStarted = false;

	// Finalize the civilizations of the game
	for each (auto& civ in _civilizations)
	{
		civ.second->finalize();
		delete civ.second;
	}
}

const sim::GameClock & sim::Game::getGameClock() const
{
	return _gameClock;
}

bool sim::Game::loadCivilizations()
{
	// Add all civilizations to the game 
	auto civNameList = _resManager->getResource<NamesFileResource>("CivilizationNames")->getNamesList();
	for each (auto& name in civNameList)
	{
		_civilizations[name] = new Civilization(name);
		if (!_civilizations[name]->initialize())
			return false;
	}

	return true;
}
