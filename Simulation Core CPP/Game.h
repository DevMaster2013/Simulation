#pragma once

#include "DLLExportDefinitions.h"
#include "HelpfulMacros.h"
#include "SimTypes.h"
#include "Civilization.h"
#include "GameClock.h"
#include "ResourceManager.h"
#include "Player.h"
#include <map>

namespace sim
{
	class SIMAPI Game
	{
		DECLARE_SINGLETON(Game)

	public:
		bool initializeGame();
		void runGame();
		void finalizeGame();

	public:
		const GameClock& getGameClock() const;

	public:
		void addCivilization(Civilization* civilization);
		Civilization* getCivilization(const std::string& civName);
		void addPlayer(Player* player);
		Player* getPlayer(const std::string& playerName);

	private:
		bool initializeCivilizations();
		bool initializePlayers();

	private:
		bool _isGameStarted;
		StringMap<Civilization*> _civilizations;
		StringMap<Player*> _gamePlayers;
		GameClock _gameClock;
		ResourceManager* _resManager;
	};
}