#include "FinancialSystem.h"

sim::FinancialSystem::FinancialSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "FinancialSystem")
{
}

sim::FinancialSystem::~FinancialSystem()
{
}

bool sim::FinancialSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::FinancialSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::FinancialSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
