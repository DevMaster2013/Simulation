#include "ResearchSystem.h"

sim::ResearchSystem::ResearchSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "ResearchSystem")
{
}

sim::ResearchSystem::~ResearchSystem()
{
}

bool sim::ResearchSystem::Initialize()
{
	return true;
}

void sim::ResearchSystem::Update(double elapsedDays)
{
}

void sim::ResearchSystem::Finalize()
{
}
