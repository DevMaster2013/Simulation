#include "CivilizationSystem.h"
#include "Civilization.h"

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

bool sim::CivilizationSystem::Initialize()
{
	return true;
}

void sim::CivilizationSystem::Update(double elapsedDays)
{
	for each (auto& subSystem in _subSystems)
	{
		subSystem.second->Update(elapsedDays);
	}
}

void sim::CivilizationSystem::Finalize()
{
	for each (auto& subSystem in _subSystems)
	{
		subSystem.second->Finalize();
		delete subSystem.second;
	}
	_subSystems.clear();
}

sim::Civilization* sim::CivilizationSystem::GetOwnerCivilization() const
{
	return _ownerCivilization;
}

sim::CivilizationSystem * sim::CivilizationSystem::GetParentSystem() const
{
	return _parentSystem;
}

void sim::CivilizationSystem::SetOwnerCivilizatoin(sim::Civilization* ownerCiv)
{
	_ownerCivilization = ownerCiv;
}

void sim::CivilizationSystem::SetParentSystem(CivilizationSystem * parentSystem)
{
	_parentSystem = parentSystem;
}

void sim::CivilizationSystem::SetSystemConfigTable(SystemConfigTable* systemConfigTable)
{
	populateSystemConfig(systemConfigTable);
}

void sim::CivilizationSystem::populateSystemConfig(SystemConfigTable* systemConfigTable)
{
}
