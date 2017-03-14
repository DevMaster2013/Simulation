#include "TradeSystem.h"

sim::TradeSystem::TradeSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "TradeSystem")
{
}

sim::TradeSystem::~TradeSystem()
{
}

bool sim::TradeSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::TradeSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::TradeSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
