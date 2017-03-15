#pragma once

#include "ScreenResponse.h"
/*
GameScreens
	- Welcome Screen
	- MainMenu Screen
	- New Game Screen
	- Main Screen
	- Pause Screen
	- Score Screen
*/


class GameScreen
{
public:
	GameScreen();
	virtual ~GameScreen();

public:
	void showScreen();
	ScreenResponse getResponse();

private:
	void handleInput();	

protected:
	virtual void onOneTick() = 0;
	virtual void onKeyPressed(int key) = 0;

protected:
	void clearScreen();

protected:
	bool _screenShouldClosed;
	ScreenResponse _screenRespose;
};
