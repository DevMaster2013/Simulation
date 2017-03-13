#include "DefenseSystem.h"

sim::DefenseSystem::DefenseSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "DefenseSystem")
{
}

sim::DefenseSystem::~DefenseSystem()
{
}

bool sim::DefenseSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::DefenseSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::DefenseSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
