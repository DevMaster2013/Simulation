#include "TradeSystem.h"

sim::TradeSystem::TradeSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "TradeSystem")
{
}

sim::TradeSystem::~TradeSystem()
{
}

bool sim::TradeSystem::Initialize()
{
	return true;
}

void sim::TradeSystem::Update(double elapsedDays)
{
}

void sim::TradeSystem::Finalize()
{
}
