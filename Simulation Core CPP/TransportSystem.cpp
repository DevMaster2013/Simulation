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
	return true;
}

void sim::TransportSystem::Update(double elapsedDays)
{
}

void sim::TransportSystem::Finalize()
{
}
