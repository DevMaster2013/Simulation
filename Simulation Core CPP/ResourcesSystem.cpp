#include "ResourcesSystem.h"

sim::ResourcesSystem::ResourcesSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "ResourcesSystem")
{
}

sim::ResourcesSystem::~ResourcesSystem()
{
}

bool sim::ResourcesSystem::Initialize()
{
	return true;
}

void sim::ResourcesSystem::Update(double elapsedDays)
{
}

void sim::ResourcesSystem::Finalize()
{
}
