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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;

	public:
		Civilization* GetOwnerCivilization() const;
		CivilizationSystem* GetParentSystem() const;
		void SetOwnerCivilizatoin(Civilization* ownerCiv);
		void SetParentSystem(CivilizationSystem* parentSystem);
		void SetSystemConfigTable(SystemConfigTable* systemConfigTable);

	public:
		template<typename T>
		inline T* GetSubSystem();

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
	inline T * CivilizationSystem::GetSubSystem()
	{
		auto found = _subSystems.find(typeid(T).name());
		if (found == _subSystems.end())
			return nullptr;
		return (T*)found;
	}

	template<typename T>
	inline void CivilizationSystem::addSubSystem()
	{
		auto system = new T(this);
		_subSystems[typeid(T).name()] = system;
	}
}