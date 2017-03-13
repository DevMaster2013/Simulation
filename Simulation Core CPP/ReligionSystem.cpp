#include "ReligionSystem.h"

sim::ReligionSystem::ReligionSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "ReligionSystem")
{
}

sim::ReligionSystem::~ReligionSystem()
{
}

bool sim::ReligionSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::ReligionSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::ReligionSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
