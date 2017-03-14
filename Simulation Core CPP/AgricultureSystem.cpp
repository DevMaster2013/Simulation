#include "AgricultureSystem.h"

sim::AgricultureSystem::AgricultureSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "AgricultureSystem")
{
}

sim::AgricultureSystem::~AgricultureSystem()
{
}

bool sim::AgricultureSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::AgricultureSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::AgricultureSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
