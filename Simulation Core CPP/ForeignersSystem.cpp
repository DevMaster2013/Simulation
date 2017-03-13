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
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::ForeignersSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::ForeignersSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
