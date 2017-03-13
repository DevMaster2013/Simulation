#include "EducationSystem.h"

sim::EducationSystem::EducationSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "EducationSystem")
{
}

sim::EducationSystem::~EducationSystem()
{
}

bool sim::EducationSystem::Initialize()
{
	return true;
}

void sim::EducationSystem::Update(double elapsedDays)
{
}

void sim::EducationSystem::Finalize()
{
}
