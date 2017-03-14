#include "DefenseSystem.h"

sim::DefenseSystem::DefenseSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "DefenseSystem")
{
}

sim::DefenseSystem::~DefenseSystem()
{
}

bool sim::DefenseSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::DefenseSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::DefenseSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
