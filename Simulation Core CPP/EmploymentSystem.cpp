#include "EmploymentSystem.h"

sim::EmploymentSystem::EmploymentSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "EmploymentSystem")
{
}

sim::EmploymentSystem::~EmploymentSystem()
{
}

bool sim::EmploymentSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::EmploymentSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::EmploymentSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
