#include "ManufacturingSystem.h"

sim::ManufacturingSystem::ManufacturingSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ManufacturingSystem")
{
}

sim::ManufacturingSystem::~ManufacturingSystem()
{
}

bool sim::ManufacturingSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::ManufacturingSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::ManufacturingSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
