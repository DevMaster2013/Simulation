#include "EnvironmentSystem.h"

sim::EnvironmentSystem::EnvironmentSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "EnvironmentSystem")
{
}

sim::EnvironmentSystem::~EnvironmentSystem()
{
}

bool sim::EnvironmentSystem::Initialize()
{
	return true;
}

void sim::EnvironmentSystem::Update(double elapsedDays)
{
}

void sim::EnvironmentSystem::Finalize()
{
}
