#pragma once

#include "DLLExportDefinitions.h"
#include "HelpfulMacros.h"
#include "SimTypes.h"
#include "Civilization.h"
#include "GameClock.h"
#include "ResourceManager.h"
#include <map>

namespace sim
{
	class SIMAPI Game
	{
		DECLARE_SINGLETON(Game)

	public:
		bool InitializeGame();
		void RunGame();
		void FinalizeGame();

	private:
		bool loadCivilizations();

	private:
		bool _isGameStarted;
		StringMap<Civilization*> _civilizations;
		GameClock _gameClock;
		ResourceManager* _resManager;
	};
}