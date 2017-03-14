#include "ResourcesSystem.h"

sim::ResourcesSystem::ResourcesSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ResourcesSystem")
{
}

sim::ResourcesSystem::~ResourcesSystem()
{
}

bool sim::ResourcesSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::ResourcesSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::ResourcesSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
