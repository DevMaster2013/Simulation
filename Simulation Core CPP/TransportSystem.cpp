#include "TransportSystem.h"

sim::TransportSystem::TransportSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "TransportSystem")
{
}

sim::TransportSystem::~TransportSystem()
{
}

bool sim::TransportSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::TransportSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::TransportSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
