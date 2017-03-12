#include "SportsSystem.h"

sim::SportsSystem::SportsSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "SportsSystem")
{
}

sim::SportsSystem::~SportsSystem()
{
}

bool sim::SportsSystem::Initialize()
{
	return true;
}

void sim::SportsSystem::Update(double elapsedDays)
{
}

void sim::SportsSystem::Finalize()
{
}
