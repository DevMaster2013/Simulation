#include "FinancialSystem.h"

sim::FinancialSystem::FinancialSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "FinancialSystem")
{
}

sim::FinancialSystem::~FinancialSystem()
{
}

bool sim::FinancialSystem::Initialize()
{
	return true;
}

void sim::FinancialSystem::Update(double elapsedDays)
{
}

void sim::FinancialSystem::Finalize()
{
}
