#include "AgricultureSystem.h"

sim::AgricultureSystem::AgricultureSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "AgricultureSystem")
{
}

sim::AgricultureSystem::~AgricultureSystem()
{
}

bool sim::AgricultureSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::AgricultureSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::AgricultureSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
