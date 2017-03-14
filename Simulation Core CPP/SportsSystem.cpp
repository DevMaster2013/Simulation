#include "SportsSystem.h"

sim::SportsSystem::SportsSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "SportsSystem")
{
}

sim::SportsSystem::~SportsSystem()
{
}

bool sim::SportsSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::SportsSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::SportsSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
