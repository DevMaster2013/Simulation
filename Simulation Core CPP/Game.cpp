#include "Game.h"
#include "SimException.h"
#include "NamesFileResource.h"
#include <iostream>

bool sim::Game::initializeGame()
{
	// Load Game Resources
	_resManager = ResourceManager::getInstance();
	_resManager->loadAllResources();

	if (!initializePlayers())
		throw SimException("Cannot initialize players");

	if (!initializeCivilizations())
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

		// get the elapsed game time
		auto elapsedTime = _gameClock.getElapsedGameTime();

		// Update all civilizatoins of the game
		for each (auto& civ in _civilizations)
		{
			civ.second->update(elapsedTime);
		}

		// Update the players
		for each (auto& player in _gamePlayers)
		{
			player.second->update(elapsedTime);
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

	// Finalize the players
	for each (auto& player in _gamePlayers)
	{
		player.second->finalize();
		delete player.second;
	}
}

const sim::GameClock & sim::Game::getGameClock() const
{
	return _gameClock;
}

void sim::Game::addCivilization(Civilization * civilization)
{
	if (civilization == nullptr)
		return;

	auto found = _civilizations.find(civilization->getName());
	if (found == _civilizations.end())
		_civilizations[civilization->getName()] = civilization;
}

sim::Civilization * sim::Game::getCivilization(const std::string & civName)
{
	auto civ = _civilizations.find(civName);
	if (civ != _civilizations.end())
		return civ->second;
	return nullptr;
}

void sim::Game::addPlayer(Player * player)
{
	if (player == nullptr)
		return;

	auto found = _gamePlayers.find(player->getName());
	if (found == _gamePlayers.end())
		_gamePlayers[player->getName()] = player;	
}

sim::Player * sim::Game::getPlayer(const std::string & playerName)
{
	auto found = _gamePlayers.find(playerName);
	if (found != _gamePlayers.end())
		return found->second;

	return nullptr;
}

bool sim::Game::initializeCivilizations()
{
	// initialize all civilizations in the game 
	for each (auto& civ in _civilizations) 
	{
		if (!civ.second->initialize())
			return false;
	}

	return true;
}

bool sim::Game::initializePlayers()
{
	for each (auto& player in _gamePlayers)
	{
		if (!player.second->initialize())
			return false;
	}
	return true;
}
