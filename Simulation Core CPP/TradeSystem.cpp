#include "TradeSystem.h"

sim::TradeSystem::TradeSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "TradeSystem")
{
}

sim::TradeSystem::~TradeSystem()
{
}

bool sim::TradeSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::TradeSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::TradeSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
