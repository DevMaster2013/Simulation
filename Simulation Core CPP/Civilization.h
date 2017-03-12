#pragma once

#include "DLLExportDefinitions.h"
#include "HelpfulMacros.h"
#include "SimTypes.h"
#include "GameEntity.h"
#include "CivilizationSystem.h"
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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override; 
		virtual void Finalize() override;

	public:
		template<typename T>
		inline T* GetSystem();

	private:
		CivilizationSystem* getSystem(const std::string& systemName);

		template<typename T>
		inline void addSystem();

	private:
		StringMap<CivilizationSystem*> _civSystems;
	};

	template<typename T>
	inline T* Civilization::GetSystem()
	{
		auto found = getSystem(typeid(T).name());
		if (found == nullptr)
			return nullptr;
		return (T*)found;
	}

	template<typename T>
	inline void Civilization::addSystem()
	{
		_civSystems[typeid(T).name()] = new T(this);
	}
}