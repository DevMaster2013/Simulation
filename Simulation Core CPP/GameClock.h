#pragma once

#include "DLLExportDefinitions.h"

namespace sim
{
	class SIMAPI GameClock
	{
	private:
		const double DEFAULT_TIME_SCALE = 24.0;
		const double DEFAULT_START_GAME_TIME = 0;

	public:
		GameClock();
		GameClock(double timeScale);
		GameClock(double timeScale, double startGameTime);
		~GameClock();

	public:
		void Start();
		double GetElapsedSeconds();
		double GetElapsedGameTime();

	public:
		void SetTimeScale(double timeScale);
		void SetStartGameTime(double startGameTime);
		double GetTimeScale() const;
		double GetStartGameTime() const;

	private:
		double _clockFrequency;
		double _currentTime;
		double _startingGameTime;
		double _timeScale;
	};
}
