#include "SocialSystem.h"

sim::SocialSystem::SocialSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "SocialSystem")
{
}

sim::SocialSystem::~SocialSystem()
{
}

bool sim::SocialSystem::Initialize()
{
	if (!sim::CivilizationSystem::Initialize())
		return false;

	// Initialize the subsystems
	// The Social System has these sub systems
		// - Marriage Subsystem	--> Manage the marriage in the system
		// - Dieying Subsystem	--> manage the dieyign humans in the system
		// - Humans Subsystem	--> manage the actual humans in the system
		// - Relations SubSystem --> manage the relations of each human in the system

	return sim::CivilizationSystem::Initialize();
}

void sim::SocialSystem::Update(double elapsedDays)
{
	sim::CivilizationSystem::Update(elapsedDays);
}

void sim::SocialSystem::Finalize()
{
	sim::CivilizationSystem::Finalize();
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
	_socialConfig.MaximumNumberOfChildren = systemConfigTable->GetValue<int>("MaximumNumberOfChildren");
}
