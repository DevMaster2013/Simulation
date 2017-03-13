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
	return true;
}

void sim::EmploymentSystem::Update(double elapsedDays)
{
}

void sim::EmploymentSystem::Finalize()
{
}
