#include "SupplySystem.h"

sim::SupplySystem::SupplySystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "SupplySystem")
{
}

sim::SupplySystem::~SupplySystem()
{
}

bool sim::SupplySystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::SupplySystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::SupplySystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
