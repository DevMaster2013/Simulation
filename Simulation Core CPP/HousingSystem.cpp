#include "HousingSystem.h"

sim::HousingSystem::HousingSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "HousingSystem")
{
}

sim::HousingSystem::~HousingSystem()
{
}

bool sim::HousingSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::HousingSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::HousingSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
