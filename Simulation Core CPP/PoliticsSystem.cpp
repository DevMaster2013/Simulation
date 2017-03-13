#include "PoliticsSystem.h"

sim::PoliticsSystem::PoliticsSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "PoliticsSystem")
{
}

sim::PoliticsSystem::~PoliticsSystem()
{
}

bool sim::PoliticsSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::PoliticsSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::PoliticsSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
