#include "PoliticsSystem.h"

sim::PoliticsSystem::PoliticsSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "PoliticsSystem")
{
}

sim::PoliticsSystem::~PoliticsSystem()
{
}

bool sim::PoliticsSystem::Initialize()
{
	return true;
}

void sim::PoliticsSystem::Update(double elapsedDays)
{
}

void sim::PoliticsSystem::Finalize()
{
}
