#include "GameScreen.h"
#include "ConsoleKeys.h"
#include <iostream>
#include <conio.h>

GameScreen::GameScreen()
	: _screenShouldClosed(false)
	, _screenRespose(ScreenResponse::NoResponse)
{
}

GameScreen::~GameScreen()
{
}

void GameScreen::showScreen()
{	
	while (!_screenShouldClosed)
	{
		// clear screen
		clearScreen();

		// call the update
		onOneTick();		

		// handle the input
		handleInput();
	}
}

void GameScreen::handleInput()
{
	// check if there is input
	if (int key = _getch()) {
		
		if (key == KEY_ESCAPE)
		{
			std::cout << "Are you sure you want to exit the game? ";
			int answer = _getch();
			if (answer == 'y' || answer == 'Y')
			{
				_screenShouldClosed = true;
				_screenRespose = ScreenResponse::GameShouldClosed;
			}
		}

		onKeyPressed(key);
	}
}

ScreenResponse GameScreen::getResponse()
{
	return _screenRespose;
}

void GameScreen::clearScreen()
{
	system("cls");
}
