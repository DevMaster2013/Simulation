#include "ResearchSystem.h"

sim::ResearchSystem::ResearchSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ResearchSystem")
{
}

sim::ResearchSystem::~ResearchSystem()
{
}

bool sim::ResearchSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::ResearchSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::ResearchSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
