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
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::EducationSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::EducationSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
