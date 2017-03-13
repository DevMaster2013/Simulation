#include "ConstructionSystem.h"

sim::ConstructionSystem::ConstructionSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ConstructionSystem")
{
}

sim::ConstructionSystem::~ConstructionSystem()
{
}

bool sim::ConstructionSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::ConstructionSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::ConstructionSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
