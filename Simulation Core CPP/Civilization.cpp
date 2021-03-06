#include "Civilization.h"
#include "SimException.h"
#include "ResourceManager.h"

#include "AgricultureSystem.h"
#include "CommunicationSystem.h"
#include "ConstructionSystem.h"
#include "DefenseSystem.h"
#include "DiplomacySystem.h"
#include "EducationSystem.h"
#include "EmploymentSystem.h"
#include "EntertainmentSystem.h"
#include "EnvironmentSystem.h"
#include "FacilitiesSystem.h"
#include "ForeignersSystem.h"
#include "FinancialSystem.h"
#include "HealthSystem.h"
#include "HousingSystem.h"
#include "ManufacturingSystem.h"
#include "PoliticsSystem.h"
#include "ReligionSystem.h"
#include "ResearchSystem.h"
#include "ResourcesSystem.h"
#include "SecuritySystem.h"
#include "SocialSystem.h"
#include "SportsSystem.h"
#include "SupplySystem.h"
#include "TradeSystem.h"
#include "TransportSystem.h"

sim::Civilization::Civilization()
	: GameEntity()
{
}

sim::Civilization::Civilization(const std::string & name)
	: GameEntity(name)
{
}

sim::Civilization::~Civilization()
{
}

void sim::Civilization::update(double elapsedDays)
{
	for each (auto& sys in _civSystems)
	{
		sys.second->update(elapsedDays);
	}
}

bool sim::Civilization::initialize()
{
	// Load the systems config file resource
	_systemsConfigRes = ResourceManager::getInstance()->getResource<ConfigFileResource>("SystemsConfig");

	// Add the List of Civilization Systems
	addSystem<AgricultureSystem>();
	addSystem<CommunicationSystem>();
	addSystem<ConstructionSystem>();
	addSystem<DefenseSystem>();
	addSystem<DiplomacySystem>();
	addSystem<EducationSystem>();
	addSystem<EmploymentSystem>();
	addSystem<EntertainmentSystem>();
	addSystem<EnvironmentSystem>();
	addSystem<FacilitiesSystem>();
	addSystem<FinancialSystem>();
	addSystem<ForeignersSystem>();
	addSystem<HealthSystem>();
	addSystem<HousingSystem>();
	addSystem<ManufacturingSystem>();
	addSystem<PoliticsSystem>();
	addSystem<ReligionSystem>();
	addSystem<ResearchSystem>();
	addSystem<ResourcesSystem>();
	addSystem<SecuritySystem>();
	addSystem<SocialSystem>();
	addSystem<SportsSystem>();
	addSystem<SupplySystem>();
	addSystem<TradeSystem>();
	addSystem<TransportSystem>();

	for each (auto& sys in _civSystems)
	{
		if (!sys.second->initialize())
			throw SimException("Cannot initialize the system (" + sys.second->getName() + ") in civilization (" + _name + ")");
	}

	return true;
}

void sim::Civilization::finalize()
{
	for each (auto& sys in _civSystems)
	{
		sys.second->finalize();
		delete sys.second;
	}	
}

void sim::Civilization::sendMessage(bool isInternal, IPostParticipant * sender, IPostParticipant * reciever, Message * content, Priority priority)
{
	// get the communication system
	auto commSystem = getSystem<CommunicationSystem>();
	commSystem->sendMessage(isInternal, sender, reciever, content, priority);
}

sim::CivilizationSystem* sim::Civilization::getSystem(const std::string & systemName)
{
	auto found = _civSystems.find(systemName);
	if (found != _civSystems.end())
		return found->second;
	return nullptr;
}

