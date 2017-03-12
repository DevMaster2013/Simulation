#include "CivilizationSystem.h"
#include "Civilization.h"

sim::CivilizationSystem::CivilizationSystem(sim::Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, "No Name")
{
}

sim::CivilizationSystem::CivilizationSystem(sim::Civilization* ownerCiv, const std::string & name)
	: GameEntity(name)
{
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
}

void sim::CivilizationSystem::Finalize()
{
}

sim::Civilization* sim::CivilizationSystem::GetOwnerCivilization() const
{
	return _ownerCivilization;
}

void sim::CivilizationSystem::SetOwnerCivilizatoin(sim::Civilization* ownerCiv)
{
}
