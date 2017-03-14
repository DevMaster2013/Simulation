#include "CiviliansSubSystem.h"
#include "Game.h"

sim::GameID sim::CiviliansSubSystem::_globalCivilianIDCounter = 1;

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
		if (!civ.second.civilian->initialize())
			return false;
	}

	return true;
}

void sim::CiviliansSubSystem::update(double elapsedDays)
{
	// Update all civlians
	for each (auto& civ in _civilians)
	{
		civ.second.civilian->update(elapsedDays);
	}
}

void sim::CiviliansSubSystem::finalize()
{
	// Delete the civilian list
	for each (auto& civ in _civilians)
	{
		civ.second.civilian->finalize();
		delete civ.second.civilian;
	}
}

void sim::CiviliansSubSystem::registerNewCivilian(Civilian * newCivilian)
{
	// Ask the Civilian Sub System to generate new ID for the civilian
	GameID newID = generateNewID();
	newCivilian->setCivilianID(newID);

	// Set the home civilian civilization
	newCivilian->setHomeCivilization(this->_ownerCivilization);

	// Initialize the civilian
	newCivilian->initialize();

	// Create the record
	CivilianRecord record;
	record.registerDate = Game::getInstance()->getGameClock().getCurrentGameTime();
	record.civilian = newCivilian;

	// Add the civilian record to the sub system
	_civilians[newID] = record;
}

const sim::CivilianRecord* sim::CiviliansSubSystem::unregisterCivilian(Civilian * civilian)
{
	// Get the civilian Record
	auto& ID = civilian->getCivilianID();
	auto civilianRecord = getCivilianRecord(ID);

	// check if the civilian is registered
	if (civilianRecord == nullptr)
		return nullptr;

	// Remove the civilian record from the system
	_civilians.erase(ID);

	// return the erased civilization record
	return civilianRecord;
}

const sim::IDMap<sim::CivilianRecord>& sim::CiviliansSubSystem::getCivilianRecords() const
{
	return _civilians;
}

const sim::CivilianRecord* sim::CiviliansSubSystem::getCivilianRecord(const GameID & civID) const
{
	auto found = _civilians.find(civID);
	if (found != _civilians.end())
		return &(found->second);
	return nullptr;
}

int sim::CiviliansSubSystem::getInitialPopulationFamilies() const
{
	return _initialPopulationFamilies;
}

void sim::CiviliansSubSystem::populateSystemConfig(SystemConfigTable * systemConfigTable)
{
	_initialPopulationFamilies = systemConfigTable->getValue<int>("InitialPopulationFamilies");	
}

sim::GameID sim::CiviliansSubSystem::generateNewID()
{
	return _globalCivilianIDCounter++;
}

void sim::CiviliansSubSystem::registerInitialPopulations()
{
	// TODO : add the initial population to the system
}
