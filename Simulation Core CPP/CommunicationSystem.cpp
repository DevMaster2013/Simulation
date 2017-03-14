#include "CommunicationSystem.h"

sim::CommunicationSystem::CommunicationSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "CommunicationSystem")
{
}

sim::CommunicationSystem::~CommunicationSystem()
{
}

bool sim::CommunicationSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::CommunicationSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::CommunicationSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
