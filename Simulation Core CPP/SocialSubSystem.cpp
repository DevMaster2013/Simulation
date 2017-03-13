#include "SocialSubSystem.h"
#include "SocialSubSystem.h"

sim::SocialSubSystem::SocialSubSystem(Civilization * ownerCiv, SocialSystem* socialSystem, const std::string & name)
	: CivilizationSystem(ownerCiv, (CivilizationSystem*)socialSystem, name)
{
}

sim::SocialSubSystem::~SocialSubSystem()
{
}

bool sim::SocialSubSystem::Initialize()
{
	if (!CivilizationSystem::Initialize())
		return false;

	return true;
}

void sim::SocialSubSystem::Update(double elapsedDays)
{
	CivilizationSystem::Update(elapsedDays);
}

void sim::SocialSubSystem::Finalize()
{
	CivilizationSystem::Finalize();
}

sim::SocialSystem * sim::SocialSubSystem::GetSocialSystem() const
{
	return (SocialSystem*)_parentSystem;
}

void sim::SocialSubSystem::populateSystemConfig(SystemConfigTable * systemConfigTable)
{
}
