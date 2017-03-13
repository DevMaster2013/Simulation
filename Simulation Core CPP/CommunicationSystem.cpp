#include "CommunicationSystem.h"

sim::CommunicationSystem::CommunicationSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "CommunicationSystem")
{
}

sim::CommunicationSystem::~CommunicationSystem()
{
}

bool sim::CommunicationSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::CommunicationSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::CommunicationSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
}
