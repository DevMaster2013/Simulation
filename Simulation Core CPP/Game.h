#pragma once

#include "DLLExportDefinitions.h"
#include "HelpfulMacros.h"
#include "SimTypes.h"
#include "Civilization.h"
#include "GameClock.h"
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
		bool _isGameStarted;
		StringMap<Civilization*> _civilizations;
		GameClock _gameClock;
	};
}