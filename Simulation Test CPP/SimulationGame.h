#pragma once

#include "GameScreen.h"

class SimulationGame
{
public:
	SimulationGame();
	~SimulationGame();

public:
	bool initializeGame();
	void runGame();
	void finalizeGame();

private:
	GameScreen* _currentGameScreen;
};
