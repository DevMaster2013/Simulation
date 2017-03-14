#include "EducationSystem.h"

sim::EducationSystem::EducationSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "EducationSystem")
{
}

sim::EducationSystem::~EducationSystem()
{
}

bool sim::EducationSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::EducationSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::EducationSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
