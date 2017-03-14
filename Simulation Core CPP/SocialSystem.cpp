#include "SocialSystem.h"
#include "CiviliansSubSystem.h"

sim::SocialSystem::SocialSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "SocialSystem")
{
}

sim::SocialSystem::~SocialSystem()
{
}

bool sim::SocialSystem::initialize()
{
	// Initialize the subsystems
	// - Marriage Subsystem	--> Manage the marriage in the system
	// - Dieying Subsystem	--> manage the dieyign humans in the system
	// - Relations SubSystem --> manage the relations of each human in the system

	addSubSystem<CiviliansSubSystem>();

	if (!sim::CivilizationSystem::initialize())
		return false;

	return true;
}

void sim::SocialSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::SocialSystem::finalize()
{
	sim::CivilizationSystem::finalize();
}


void sim::SocialSystem::populateSystemConfig(SystemConfigTable* systemConfigTable)
{	
	//_socialConfig.MinimumManMarriageAge = systemConfigTable->getValue<double>("MinimumManMarriageAge");
	//_socialConfig.MinimumWomanMarriageAge = systemConfigTable->getValue<double>("MinimumWomanMarriageAge");
	//_socialConfig.MaximumNumberOfChildren = systemConfigTable->getValue<int>("MaximumNumberOfChildren");

	sim::CivilizationSystem::populateSystemConfig(systemConfigTable);
}
