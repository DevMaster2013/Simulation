#include "FacilitiesSystem.h"

sim::FacilitiesSystem::FacilitiesSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "FacilitiesSystem")
{
}

sim::FacilitiesSystem::~FacilitiesSystem()
{
}

bool sim::FacilitiesSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::FacilitiesSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::FacilitiesSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
