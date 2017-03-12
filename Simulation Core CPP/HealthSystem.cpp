#include "HealthSystem.h"

sim::HealthSystem::HealthSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "HealthSystem")
{
}

sim::HealthSystem::~HealthSystem()
{
}

bool sim::HealthSystem::Initialize()
{
	return true;
}

void sim::HealthSystem::Update(double elapsedDays)
{
}

void sim::HealthSystem::Finalize()
{
}
