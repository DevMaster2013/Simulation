#include "SportsSystem.h"

sim::SportsSystem::SportsSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "SportsSystem")
{
}

sim::SportsSystem::~SportsSystem()
{
}

bool sim::SportsSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::SportsSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::SportsSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
