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
		CivilizationSystem(Civilization* ownerCiv);
		CivilizationSystem(Civilization* ownerCiv, const std::string& name);
		virtual ~CivilizationSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;

	public:
		Civilization* GetOwnerCivilization() const;
		void SetOwnerCivilizatoin(Civilization* ownerCiv);

	protected:
		Civilization* _ownerCivilization;
		SystemConfigTable* _systemConfigTable;
	};
}