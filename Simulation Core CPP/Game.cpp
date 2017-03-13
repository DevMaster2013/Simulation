#include "Game.h"
#include "SimException.h"
#include "NamesFileResource.h"
#include <iostream>

bool sim::Game::InitializeGame()
{
	// Load Game Resources
	_resManager = ResourceManager::GetInstance();
	_resManager->LoadAllResources();

	if (!loadCivilizations())
		throw SimException("Cannot initialize civilizations");

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

bool sim::Game::loadCivilizations()
{
	// Add all civilizations to the game 
	auto civNameList = _resManager->GetResource<NamesFileResource>("CivilizationNames")->GetNamesList();
	for each (auto& name in civNameList)
	{
		_civilizations[name] = new Civilization(name);
		if (!_civilizations[name]->Initialize())
			return false;
	}

	return true;
}
