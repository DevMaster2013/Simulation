#include "SupplySystem.h"

sim::SupplySystem::SupplySystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "SupplySystem")
{
}

sim::SupplySystem::~SupplySystem()
{
}

bool sim::SupplySystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::SupplySystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::SupplySystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
