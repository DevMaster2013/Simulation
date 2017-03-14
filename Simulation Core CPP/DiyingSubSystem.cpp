#include "DiyingSubSystem.h"
#include "Game.h"
#include "CivilianDeadMessage.h"

sim::DiyingSubSystem::DiyingSubSystem(Civilization * ownerCiv, CivilizationSystem * socialSystem)
	: SocialSubSystem(ownerCiv, socialSystem, "CivilianSubSystem")
{
}

sim::DiyingSubSystem::~DiyingSubSystem()
{
}

bool sim::DiyingSubSystem::initialize()
{
	return true;
}

void sim::DiyingSubSystem::update(double /*elapsedDays*/)
{
}

void sim::DiyingSubSystem::finalize()
{
	// Delete the civilian list
	for each (auto& civ in _deads)
	{
		civ.second.civilian->finalize();
		delete civ.second.civilian;
	}
}

void sim::DiyingSubSystem::registerNewDeadRecord(Civilian * deadCivilian)
{
	// Get the civilian ID
	auto& ID = deadCivilian->getCivilianID();
	
	// Create the record
	CivilianDieRecord record;
	record.deathDate = Game::getInstance()->getGameClock().getCurrentGameTime();
	record.civilian = deadCivilian;

	// Add the civilian record to the sub system
	_deads[ID] = record;

}

const sim::IDMap<sim::CivilianDieRecord>& sim::DiyingSubSystem::getCivilianDieRecords() const
{
	return _deads;
}

const sim::CivilianDieRecord* sim::DiyingSubSystem::getCivilianDieRecord(const GameID & civID) const
{
	auto found = _deads.find(civID);
	if (found != _deads.end())
		return &(found->second);
	return nullptr;
}

double sim::DiyingSubSystem::getMaximumAge() const
{
	return _maximumAge;
}

void sim::DiyingSubSystem::populateSystemConfig(SystemConfigTable * systemConfigTable)
{
	_maximumAge = systemConfigTable->getValue<double>("MaximumAge");
}

void sim::DiyingSubSystem::handleMessage(IPostParticipant* /*sender*/, Message* message)
{
	auto messageTypeID = message->getMessageTypeID();
	if (messageTypeID == MessageTypeID::CivilianDeadMessage)
	{
		CivilianDeadMessage* deadMessage = (CivilianDeadMessage*)message;
		registerNewDeadRecord(deadMessage->getCivilian());
	}	
}
