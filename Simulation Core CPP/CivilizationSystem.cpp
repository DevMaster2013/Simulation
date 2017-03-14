#include "CivilizationSystem.h"
#include "Civilization.h"
#include "CommunicationSystem.h"

sim::CivilizationSystem::CivilizationSystem(sim::Civilization* ownerCiv, CivilizationSystem* parentSystem)
	: CivilizationSystem(ownerCiv, parentSystem, "No Name")
{
}

sim::CivilizationSystem::CivilizationSystem(sim::Civilization* ownerCiv, CivilizationSystem* parentSystem, const std::string & name)
	: GameEntity(name)
{
	_ownerCivilization = ownerCiv;
	_parentSystem = parentSystem;
}

sim::CivilizationSystem::~CivilizationSystem()
{
}

bool sim::CivilizationSystem::initialize()
{
	for each (auto& subSystem in _subSystems)
	{
		if (!subSystem.second->initialize())
			return false;
	}

	return true;
}

void sim::CivilizationSystem::update(double elapsedDays)
{
	for each (auto& subSystem in _subSystems)
	{
		subSystem.second->update(elapsedDays);
	}
}

void sim::CivilizationSystem::finalize()
{
	for each (auto& subSystem in _subSystems)
	{
		subSystem.second->finalize();
		delete subSystem.second;
	}
	_subSystems.clear();
}

sim::Civilization* sim::CivilizationSystem::getOwnerCivilization() const
{
	return _ownerCivilization;
}

sim::CivilizationSystem * sim::CivilizationSystem::getParentSystem() const
{
	return _parentSystem;
}

void sim::CivilizationSystem::setOwnerCivilizatoin(sim::Civilization* ownerCiv)
{
	_ownerCivilization = ownerCiv;
}

void sim::CivilizationSystem::setParentSystem(CivilizationSystem * parentSystem)
{
	_parentSystem = parentSystem;
}

void sim::CivilizationSystem::setSystemConfigTable(SystemConfigTable* systemConfigTable)
{
	populateSystemConfig(systemConfigTable);
}

void sim::CivilizationSystem::populateSystemConfig(SystemConfigTable* systemConfigTable)
{
	for each (auto& subSystem in _subSystems)
	{
		subSystem.second->populateSystemConfig(systemConfigTable);
	}
}

void sim::CivilizationSystem::handleMessage(IPostParticipant * sender, Message * message)
{	
	for each (auto& subSystem in _subSystems)
	{
		subSystem.second->handleMessage(sender, message);
	}
}
