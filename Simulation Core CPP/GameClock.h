#pragma once

#include "DLLExportDefinitions.h"

namespace sim
{
	const double DEFAULT_TIME_SCALE = 24.0;
	const double DEFAULT_START_GAME_TIME = 0;

	class SIMAPI GameClock
	{
	public:
		GameClock();
		GameClock(double timeScale);
		GameClock(double timeScale, double startGameTime);
		~GameClock();

	public:
		void start();
		double getElapsedSeconds() const;
		double getElapsedGameTime() const;
		double getCurrentGameTime() const;

	public:
		void setTimeScale(double timeScale);
		void setStartGameTime(double startGameTime);
		double getTimeScale() const;
		double getStartGameTime() const;

	private:
		double _clockFrequency;
		double _currentTime;
		double _startingRealTime;
		double _startingGameTime;
		double _timeScale;
	};
}
