#include "GameClock.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

sim::GameClock::GameClock()
	: GameClock(DEFAULT_TIME_SCALE, DEFAULT_START_GAME_TIME)
{
	
}

sim::GameClock::GameClock(double timeScale)
	: GameClock(timeScale, DEFAULT_START_GAME_TIME)
{
}

sim::GameClock::GameClock(double timeScale, double startGameTime)
{	
	_timeScale = timeScale;

	LARGE_INTEGER current, frequency;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&current);

	_clockFrequency = double(frequency.QuadPart);
	_startingRealTime = _currentTime = double(current.QuadPart);
	_startingGameTime = startGameTime;
}

sim::GameClock::~GameClock()
{
}

void sim::GameClock::start()
{
	LARGE_INTEGER current;
	QueryPerformanceCounter(&current);
	_currentTime = double(current.QuadPart);
}

double sim::GameClock::getElapsedSeconds() const
{
	LARGE_INTEGER current;
	QueryPerformanceCounter(&current);
	return (double(current.QuadPart) - _currentTime) / _clockFrequency;
}

double sim::GameClock::getElapsedGameTime() const
{
	return getElapsedSeconds() * _timeScale;
}

double sim::GameClock::getCurrentGameTime() const
{
	LARGE_INTEGER current;
	QueryPerformanceCounter(&current);
	double elapsedRealTime = (double(current.QuadPart) - _startingRealTime) / _clockFrequency;
	return elapsedRealTime * _timeScale + _startingGameTime;
}

void sim::GameClock::setTimeScale(double timeScale)
{
	_timeScale = timeScale;
}

void sim::GameClock::setStartGameTime(double startGameTime)
{
	_startingGameTime = startGameTime;
}

double sim::GameClock::getTimeScale() const
{
	return _timeScale;
}

double sim::GameClock::getStartGameTime() const
{
	return _startingGameTime;
}
