#include "SecuritySystem.h"

sim::SecuritySystem::SecuritySystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "SecuritySystem")
{
}

sim::SecuritySystem::~SecuritySystem()
{
}

bool sim::SecuritySystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::SecuritySystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::SecuritySystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
