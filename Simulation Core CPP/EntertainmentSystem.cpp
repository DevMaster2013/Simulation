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
	return true;
}

void sim::EntertainmentSystem::Update(double elapsedDays)
{
}

void sim::EntertainmentSystem::Finalize()
{
}
