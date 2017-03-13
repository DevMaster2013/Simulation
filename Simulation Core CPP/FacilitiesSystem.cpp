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
	return true;
}

void sim::FacilitiesSystem::Update(double elapsedDays)
{
}

void sim::FacilitiesSystem::Finalize()
{
}
