#include "SupplySystem.h"

sim::SupplySystem::SupplySystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "SupplySystem")
{
}

sim::SupplySystem::~SupplySystem()
{
}

bool sim::SupplySystem::Initialize()
{
	return true;
}

void sim::SupplySystem::Update(double elapsedDays)
{
}

void sim::SupplySystem::Finalize()
{
}
