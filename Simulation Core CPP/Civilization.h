#pragma once

#include "DLLExportDefinitions.h"
#include "HelpfulMacros.h"
#include "SimTypes.h"
#include "GameEntity.h"
#include "CivilizationSystem.h"
#include "ConfigFileResource.h"
#include <string>

namespace sim
{
	class SIMAPI Civilization : public GameEntity
	{
	public:
		Civilization();
		Civilization(const std::string& name);
		~Civilization();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override; 
		virtual void finalize() override;

	public:
		template<typename T>
		inline T* getSystem();

	private:
		CivilizationSystem* getSystem(const std::string& systemName);

		template<typename T>
		inline void addSystem();

	private:
		StringMap<CivilizationSystem*> _civSystems;
		ConfigFileResource* _systemsConfigRes;
	};

	template<typename T>
	inline T* Civilization::getSystem()
	{
		auto found = getSystem(typeid(T).name());
		if (found == nullptr)
			return nullptr;
		return (T*)found;
	}

	template<typename T>
	inline void Civilization::addSystem()
	{
		auto system = new T(this);	
		auto configTable = _systemsConfigRes->getConfigTable(system->getName());
		system->setSystemConfigTable(configTable);

		_civSystems[typeid(T).name()] = system;
	}
}