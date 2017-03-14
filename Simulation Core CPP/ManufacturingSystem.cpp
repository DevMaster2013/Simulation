#include "ManufacturingSystem.h"

sim::ManufacturingSystem::ManufacturingSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ManufacturingSystem")
{
}

sim::ManufacturingSystem::~ManufacturingSystem()
{
}

bool sim::ManufacturingSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::ManufacturingSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::ManufacturingSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
