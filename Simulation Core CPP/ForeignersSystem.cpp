#include "ForeignersSystem.h"

sim::ForeignersSystem::ForeignersSystem(Civilization * ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ForeignersSystem")
{
}

sim::ForeignersSystem::~ForeignersSystem()
{
}

bool sim::ForeignersSystem::Initialize()
{
	return true;
}

void sim::ForeignersSystem::Update(double elapsedDays)
{
}

void sim::ForeignersSystem::Finalize()
{
}
