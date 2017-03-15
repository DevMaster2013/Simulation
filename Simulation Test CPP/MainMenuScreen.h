#pragma once

#include "GameScreen.h"

class MainMenuScreen : public GameScreen
{
public:
	MainMenuScreen();
	virtual ~MainMenuScreen();

protected:
	virtual void onOneTick() override;
	virtual void onKeyPressed(int key) override;
};
