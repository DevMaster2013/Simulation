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
	return true;
}

void sim::ManufacturingSystem::Update(double elapsedDays)
{
}

void sim::ManufacturingSystem::Finalize()
{
}
