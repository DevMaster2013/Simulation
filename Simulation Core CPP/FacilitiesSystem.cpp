#include "FacilitiesSystem.h"

sim::FacilitiesSystem::FacilitiesSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "FacilitiesSystem")
{
}

sim::FacilitiesSystem::~FacilitiesSystem()
{
}

bool sim::FacilitiesSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::FacilitiesSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::FacilitiesSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
