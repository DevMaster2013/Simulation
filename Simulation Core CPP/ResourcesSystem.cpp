#include "ResourcesSystem.h"

sim::ResourcesSystem::ResourcesSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ResourcesSystem")
{
}

sim::ResourcesSystem::~ResourcesSystem()
{
}

bool sim::ResourcesSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::ResourcesSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::ResourcesSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
