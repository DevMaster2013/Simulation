#include "HealthSystem.h"

sim::HealthSystem::HealthSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "HealthSystem")
{
}

sim::HealthSystem::~HealthSystem()
{
}

bool sim::HealthSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::HealthSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::HealthSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
