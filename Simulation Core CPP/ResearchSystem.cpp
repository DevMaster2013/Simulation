#include "ResearchSystem.h"

sim::ResearchSystem::ResearchSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ResearchSystem")
{
}

sim::ResearchSystem::~ResearchSystem()
{
}

bool sim::ResearchSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::ResearchSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::ResearchSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
