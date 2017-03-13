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
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::HousingSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::HousingSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
