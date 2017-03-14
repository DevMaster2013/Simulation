#include "TransportSystem.h"

sim::TransportSystem::TransportSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "TransportSystem")
{
}

sim::TransportSystem::~TransportSystem()
{
}

bool sim::TransportSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::TransportSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::TransportSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
