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
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::SecuritySystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::SecuritySystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
