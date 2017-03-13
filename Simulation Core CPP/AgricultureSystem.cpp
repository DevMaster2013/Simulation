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
	return true;
}

void sim::AgricultureSystem::Update(double elapsedDays)
{
}

void sim::AgricultureSystem::Finalize()
{
}
