#include "SecuritySystem.h"

sim::SecuritySystem::SecuritySystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "SecuritySystem")
{
}

sim::SecuritySystem::~SecuritySystem()
{
}

bool sim::SecuritySystem::Initialize()
{
	return true;
}

void sim::SecuritySystem::Update(double elapsedDays)
{
}

void sim::SecuritySystem::Finalize()
{
}
