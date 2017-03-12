#include "SocialSystem.h"

sim::SocialSystem::SocialSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "SocialSystem")
{
}

sim::SocialSystem::~SocialSystem()
{
}

bool sim::SocialSystem::Initialize()
{
	return true;
}

void sim::SocialSystem::Update(double elapsedDays)
{
}

void sim::SocialSystem::Finalize()
{
}
