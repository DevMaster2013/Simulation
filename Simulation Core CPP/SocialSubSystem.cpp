#include "SocialSubSystem.h"
#include "SocialSubSystem.h"

sim::SocialSubSystem::SocialSubSystem(Civilization * ownerCiv, CivilizationSystem* socialSystem, const std::string & name)
	: CivilizationSystem(ownerCiv, socialSystem, name)
{
}

sim::SocialSubSystem::~SocialSubSystem()
{
}

bool sim::SocialSubSystem::initialize()
{
	if (!CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::SocialSubSystem::update(double elapsedDays)
{
	CivilizationSystem::update(elapsedDays);
}

void sim::SocialSubSystem::finalize()
{
	CivilizationSystem::finalize();
}

sim::SocialSystem * sim::SocialSubSystem::getSocialSystem() const
{
	return (SocialSystem*)_parentSystem;
}
