#include "MainMenuScreen.h"
#include <iostream>
#include <conio.h>

MainMenuScreen::MainMenuScreen()
{
}

MainMenuScreen::~MainMenuScreen()
{
}

void MainMenuScreen::onOneTick()
{
	std::cout << "Welcome to Simulation Game... Please Choose what you need to do: \n\n";
	std::cout << "  1 - Start a new Game.\n";
	std::cout << "  2 - Load a Game.\n";

	std::cout << "\n\n";
	std::cout << "Enter an option: ";
}

void MainMenuScreen::onKeyPressed(int key)
{
	if (key == '1')
	{
		_screenRespose = ScreenResponse::NewGameScreen;
		_screenShouldClosed = true;
	}
	else if (key == '2')
	{
		_screenRespose = ScreenResponse::LoadGameScreen;
		_screenShouldClosed = true;
	}
}
