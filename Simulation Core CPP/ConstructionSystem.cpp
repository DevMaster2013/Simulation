#include "ConstructionSystem.h"

sim::ConstructionSystem::ConstructionSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ConstructionSystem")
{
}

sim::ConstructionSystem::~ConstructionSystem()
{
}

bool sim::ConstructionSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::ConstructionSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::ConstructionSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
