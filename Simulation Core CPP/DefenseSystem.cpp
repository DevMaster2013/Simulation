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
	return true;
}

void sim::DefenseSystem::Update(double elapsedDays)
{
}

void sim::DefenseSystem::Finalize()
{
}
