#include "DiplomacySystem.h"

sim::DiplomacySystem::DiplomacySystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "DiplomacySystem")
{
}

sim::DiplomacySystem::~DiplomacySystem()
{
}

bool sim::DiplomacySystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::DiplomacySystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::DiplomacySystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
