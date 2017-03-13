#include "HousingSystem.h"

sim::HousingSystem::HousingSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "HousingSystem")
{
}

sim::HousingSystem::~HousingSystem()
{
}

bool sim::HousingSystem::Initialize()
{
	return true;
}

void sim::HousingSystem::Update(double elapsedDays)
{
}

void sim::HousingSystem::Finalize()
{
}
