#include "EntertainmentSystem.h"

sim::EntertainmentSystem::EntertainmentSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "EntertainmentSystem")
{
}

sim::EntertainmentSystem::~EntertainmentSystem()
{
}

bool sim::EntertainmentSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::EntertainmentSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::EntertainmentSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
