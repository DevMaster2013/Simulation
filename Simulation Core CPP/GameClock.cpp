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
	_currentTime = double(current.QuadPart);
	_startingGameTime = startGameTime;
}

sim::GameClock::~GameClock()
{
}

void sim::GameClock::Start()
{
	LARGE_INTEGER current;
	QueryPerformanceCounter(&current);
	_currentTime = double(current.QuadPart);
}

double sim::GameClock::GetElapsedSeconds()
{
	LARGE_INTEGER current;
	QueryPerformanceCounter(&current);
	return (double(current.QuadPart) - _currentTime) / _clockFrequency;
}

double sim::GameClock::GetElapsedGameTime()
{
	return GetElapsedSeconds() * _timeScale + _startingGameTime;
}

void sim::GameClock::SetTimeScale(double timeScale)
{
	_timeScale = timeScale;
}

void sim::GameClock::SetStartGameTime(double startGameTime)
{
	_startingGameTime = startGameTime;
}

double sim::GameClock::GetTimeScale() const
{
	return _timeScale;
}

double sim::GameClock::GetStartGameTime() const
{
	return _startingGameTime;
}
