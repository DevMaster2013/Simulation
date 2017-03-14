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
		void start();
		double getElapsedSeconds();
		double getElapsedGameTime();

	public:
		void setTimeScale(double timeScale);
		void setStartGameTime(double startGameTime);
		double getTimeScale() const;
		double getStartGameTime() const;

	private:
		double _clockFrequency;
		double _currentTime;
		double _startingGameTime;
		double _timeScale;
	};
}
