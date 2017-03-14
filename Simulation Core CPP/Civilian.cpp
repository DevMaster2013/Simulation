#include "Civilian.h"
#include "Civilization.h"

sim::Civilian::Civilian(Civilization* civilization, const std::string & name)
	: GameEntity(name)
{
	_homeCivilization = civilization;
	_civID = UNKNOWN_ID;
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

const sim::CivilianID & sim::Civilian::getCivilianID() const
{
	return _civID;
}

void sim::Civilian::setSex(CivilianSex sex)
{
	_civilianSex = sex;
}

void sim::Civilian::setHomeCivilization(Civilization * homeCiv)
{
	_homeCivilization = homeCiv;
}

void sim::Civilian::setCivilianID(const CivilianID & newID)
{
	_civID = newID;
}
