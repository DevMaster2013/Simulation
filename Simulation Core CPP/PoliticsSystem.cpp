#include "PoliticsSystem.h"

sim::PoliticsSystem::PoliticsSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "PoliticsSystem")
{
}

sim::PoliticsSystem::~PoliticsSystem()
{
}

bool sim::PoliticsSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::PoliticsSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::PoliticsSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
