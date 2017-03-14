#include "CiviliansSubSystem.h"

sim::CivilianID sim::CiviliansSubSystem::_globalCivilianIDCounter = 1;

sim::CiviliansSubSystem::CiviliansSubSystem(Civilization * ownerCiv, CivilizationSystem * socialSystem)
	: SocialSubSystem(ownerCiv, socialSystem, "CivilianSubSystem")
{
}

sim::CiviliansSubSystem::~CiviliansSubSystem()
{
}

bool sim::CiviliansSubSystem::initialize()
{
	// Register the initial populations
	registerInitialPopulations();

	// Initialize all inital civlians
	for each (auto& civ in _civilians)
	{
		if (!civ.second->initialize())
			return false;
	}

	return true;
}

void sim::CiviliansSubSystem::update(double elapsedDays)
{
	// Update all civlians
	for each (auto& civ in _civilians)
	{
		civ.second->update(elapsedDays);
	}
}

void sim::CiviliansSubSystem::finalize()
{
	// Delete the civilian list
	for each (auto& civ in _civilians)
	{
		civ.second->finalize();
		delete civ.second;
	}
}

void sim::CiviliansSubSystem::registerNewCivilian(Civilian * newCivilian)
{
	// Ask the Civilian Sub System to generate new ID for the civilian
	CivilianID newID = generateNewID();
	newCivilian->setCivilianID(newID);

	// Set the home civilian civilization
	newCivilian->setHomeCivilization(this->_ownerCivilization);

	// Initialize the civilian
	newCivilian->initialize();

	// Add the civilian to the sub system
	_civilians[newID] = newCivilian;
}

int sim::CiviliansSubSystem::getInitialPopulationFamilies() const
{
	return _initialPopulationFamilies;
}

double sim::CiviliansSubSystem::getMaximumAge() const
{
	return _maximumAge;
}

void sim::CiviliansSubSystem::populateSystemConfig(SystemConfigTable * systemConfigTable)
{
	_initialPopulationFamilies = systemConfigTable->getValue<int>("InitialPopulationFamilies");
	_maximumAge = systemConfigTable->getValue<double>("MaximumAge");
}

sim::CivilianID sim::CiviliansSubSystem::generateNewID()
{
	return _globalCivilianIDCounter++;
}

void sim::CiviliansSubSystem::registerInitialPopulations()
{
	// TODO : add the initial population to the system
}
