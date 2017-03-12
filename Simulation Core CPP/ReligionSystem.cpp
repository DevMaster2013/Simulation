#include "ReligionSystem.h"

sim::ReligionSystem::ReligionSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "ReligionSystem")
{
}

sim::ReligionSystem::~ReligionSystem()
{
}

bool sim::ReligionSystem::Initialize()
{
	return true;
}

void sim::ReligionSystem::Update(double elapsedDays)
{
}

void sim::ReligionSystem::Finalize()
{
}
