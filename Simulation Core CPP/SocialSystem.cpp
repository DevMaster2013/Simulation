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

const sim::SocialSystem::Config & sim::SocialSystem::GetSystemConfig() const
{
	return _socialConfig;
}

void sim::SocialSystem::populateSystemConfig(SystemConfigTable* systemConfigTable)
{
	_socialConfig.MaximumAge = systemConfigTable->GetValue<double>("MaximumAge");
	_socialConfig.MinimumManMarriageAge = systemConfigTable->GetValue<double>("MinimumManMarriageAge");
	_socialConfig.MinimumWomanMarriageAge = systemConfigTable->GetValue<double>("MinimumWomanMarriageAge");
}
