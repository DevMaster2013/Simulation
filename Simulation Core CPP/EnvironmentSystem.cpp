#include "EnvironmentSystem.h"

sim::EnvironmentSystem::EnvironmentSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "EnvironmentSystem")
{
}

sim::EnvironmentSystem::~EnvironmentSystem()
{
}

bool sim::EnvironmentSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::EnvironmentSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::EnvironmentSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
