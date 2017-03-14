#include "EnvironmentSystem.h"

sim::EnvironmentSystem::EnvironmentSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "EnvironmentSystem")
{
}

sim::EnvironmentSystem::~EnvironmentSystem()
{
}

bool sim::EnvironmentSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::EnvironmentSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::EnvironmentSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
