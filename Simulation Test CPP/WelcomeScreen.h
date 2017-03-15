#pragma once

#include "GameScreen.h"

class WelcomeScreen : public GameScreen
{
public:
	WelcomeScreen();
	virtual ~WelcomeScreen();

protected:
	virtual void onOneTick() override;
	virtual void onKeyPressed(int key) override;
};
