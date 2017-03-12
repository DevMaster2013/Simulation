#include "CommunicationSystem.h"

sim::CommunicationSystem::CommunicationSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "CommunicationSystem")
{
}

sim::CommunicationSystem::~CommunicationSystem()
{
}

bool sim::CommunicationSystem::Initialize()
{
	return true;
}

void sim::CommunicationSystem::Update(double elapsedDays)
{
}

void sim::CommunicationSystem::Finalize()
{
}
