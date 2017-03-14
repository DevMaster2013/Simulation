#include "DiplomacySystem.h"

sim::DiplomacySystem::DiplomacySystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "DiplomacySystem")
{
}

sim::DiplomacySystem::~DiplomacySystem()
{
}

bool sim::DiplomacySystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::DiplomacySystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::DiplomacySystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
