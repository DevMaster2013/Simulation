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
	return true;
}

void sim::DiplomacySystem::Update(double elapsedDays)
{
}

void sim::DiplomacySystem::Finalize()
{
}
