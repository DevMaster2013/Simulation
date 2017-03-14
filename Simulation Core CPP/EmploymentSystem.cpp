#include "EmploymentSystem.h"

sim::EmploymentSystem::EmploymentSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "EmploymentSystem")
{
}

sim::EmploymentSystem::~EmploymentSystem()
{
}

bool sim::EmploymentSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::EmploymentSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::EmploymentSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
