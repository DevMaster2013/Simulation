#include "WelcomeScreen.h"
#include "ConsoleKeys.h"
#include <iostream>

WelcomeScreen::WelcomeScreen()
	: GameScreen()
{
}

WelcomeScreen::~WelcomeScreen()
{
}

void WelcomeScreen::onOneTick()
{
	std::cout << "---------------------------------------------------------------\n";
	std::cout << "                   Welcome to Simulation Game                  \n";
	std::cout << "---------------------------------------------------------------\n";
	std::cout << "Press any key to enter game...\n";
}

void WelcomeScreen::onKeyPressed(int key)
{
	if (key == KEY_RETURN)
	{
		_screenRespose = ScreenResponse::MainMenuScreen;
		_screenShouldClosed = true;
	}
}
