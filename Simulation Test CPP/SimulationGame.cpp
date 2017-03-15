#include "SimulationGame.h"
#include "WelcomeScreen.h"
#include "MainMenuScreen.h"

SimulationGame::SimulationGame()
	: _currentGameScreen(new WelcomeScreen())
{	
}

SimulationGame::~SimulationGame()
{
}

bool SimulationGame::initializeGame()
{
	return true;
}

void SimulationGame::runGame()
{	
	while (true)
	{
		if (_currentGameScreen == nullptr) continue;
		_currentGameScreen->showScreen();

		ScreenResponse response = _currentGameScreen->getResponse();
		if (response == ScreenResponse::GameShouldClosed)					
			return;		

		if (response == ScreenResponse::MainMenuScreen)
		{
			delete _currentGameScreen;
			_currentGameScreen = new MainMenuScreen();
		}
	}
}

void SimulationGame::finalizeGame()
{
	
}
