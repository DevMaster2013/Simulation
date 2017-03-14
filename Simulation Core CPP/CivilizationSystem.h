#pragma once

#include "DLLExportDefinitions.h"
#include "HelpfulMacros.h"
#include "GameEntity.h"
#include "SystemConfigTable.h"

namespace sim
{
	class SIMAPI Civilization;
	class SIMAPI CivilizationSystem : public GameEntity
	{
	public:
		CivilizationSystem(Civilization* ownerCiv, CivilizationSystem* parentSystem);
		CivilizationSystem(Civilization* ownerCiv, CivilizationSystem* parentSystem, const std::string& name);
		virtual ~CivilizationSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;

	public:
		Civilization* getOwnerCivilization() const;
		CivilizationSystem* getParentSystem() const;
		void setOwnerCivilizatoin(Civilization* ownerCiv);
		void setParentSystem(CivilizationSystem* parentSystem);
		void setSystemConfigTable(SystemConfigTable* systemConfigTable);

	public:
		template<typename T>
		inline T* getSubSystem();

	protected:
		template<typename T>
		void addSubSystem();

	protected:
		virtual void populateSystemConfig(SystemConfigTable* systemConfigTable);

	protected:
		Civilization* _ownerCivilization;
		CivilizationSystem* _parentSystem;
		StringMap<CivilizationSystem*> _subSystems;
	};

	template<typename T>
	inline T * CivilizationSystem::getSubSystem()
	{
		auto found = _subSystems.find(typeid(T).name());
		if (found == _subSystems.end())
			return nullptr;
		return (T*)found;
	}

	template<typename T>
	inline void CivilizationSystem::addSubSystem()
	{
		auto system = new T(_ownerCivilization, this);
		_subSystems[typeid(T).name()] = system;
	}
}