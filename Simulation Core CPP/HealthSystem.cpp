#include "HealthSystem.h"

sim::HealthSystem::HealthSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "HealthSystem")
{
}

sim::HealthSystem::~HealthSystem()
{
}

bool sim::HealthSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::HealthSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::HealthSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
