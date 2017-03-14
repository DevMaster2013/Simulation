#include "ReligionSystem.h"

sim::ReligionSystem::ReligionSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ReligionSystem")
{
}

sim::ReligionSystem::~ReligionSystem()
{
}

bool sim::ReligionSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::ReligionSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::ReligionSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
