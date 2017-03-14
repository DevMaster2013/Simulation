#include "EntertainmentSystem.h"

sim::EntertainmentSystem::EntertainmentSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "EntertainmentSystem")
{
}

sim::EntertainmentSystem::~EntertainmentSystem()
{
}

bool sim::EntertainmentSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::EntertainmentSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::EntertainmentSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
