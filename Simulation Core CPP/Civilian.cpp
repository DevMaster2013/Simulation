#include "Civilian.h"
#include "Civilization.h"
#include "SocialSystem.h"
#include "CommunicationSystem.h"
#include "CivilianDeadMessage.h"

sim::Civilian::Civilian(Civilization* civilization, const std::string & name)
	: GameEntity(name)
{
	_homeCivilization = civilization;
	_civID = UNKNOWN_ID;
	_age = 0;
	_estimatedDieAge = 100;
}

sim::Civilian::~Civilian()
{
}

bool sim::Civilian::initialize()
{
	return true;
}

void sim::Civilian::update(double elapsedDays)
{
	// Update the civilian age
	_age += elapsedDays;

	// check if the civilian dead
	if (_age > _estimatedDieAge)
	{
		// TODO : inform the social system that a civilian is dead through the communication system
		// by sending a message
		_homeCivilization->sendMessage(true, this, _homeCivilization->getSystem<SocialSystem>(), new CivilianDeadMessage(this), Priority::Critical);
	}
}

void sim::Civilian::finalize()
{
}

sim::CivilianSex sim::Civilian::getSex() const
{
	return _civilianSex;
}

sim::Civilization * sim::Civilian::getHomeCivilization() const
{
	return _homeCivilization;
}

const sim::GameID & sim::Civilian::getCivilianID() const
{
	return _civID;
}

double sim::Civilian::getAge() const
{
	return _age;
}

void sim::Civilian::setSex(CivilianSex sex)
{
	_civilianSex = sex;
}

void sim::Civilian::setHomeCivilization(Civilization * homeCiv)
{
	_homeCivilization = homeCiv;
}

void sim::Civilian::setCivilianID(const GameID & newID)
{
	_civID = newID;
}

void sim::Civilian::setAge(double newAge)
{
	_age = newAge;
}

void sim::Civilian::handleMessage(IPostParticipant* /*sender*/, Message* /*message*/)
{
}

