#include "ForeignersSystem.h"

sim::ForeignersSystem::ForeignersSystem(Civilization * ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ForeignersSystem")
{
}

sim::ForeignersSystem::~ForeignersSystem()
{
}

bool sim::ForeignersSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::ForeignersSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::ForeignersSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
