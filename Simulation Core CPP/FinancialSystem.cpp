#include "FinancialSystem.h"

sim::FinancialSystem::FinancialSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "FinancialSystem")
{
}

sim::FinancialSystem::~FinancialSystem()
{
}

bool sim::FinancialSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::FinancialSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::FinancialSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}
