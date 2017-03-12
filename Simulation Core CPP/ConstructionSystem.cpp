#include "ConstructionSystem.h"

sim::ConstructionSystem::ConstructionSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "ConstructionSystem")
{
}

sim::ConstructionSystem::~ConstructionSystem()
{
}

bool sim::ConstructionSystem::Initialize()
{
	return true;
}

void sim::ConstructionSystem::Update(double elapsedDays)
{
}

void sim::ConstructionSystem::Finalize()
{
}
