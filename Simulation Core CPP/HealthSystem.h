#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI HealthSystem : public CivilizationSystem
	{
	public:
		HealthSystem(Civilization* ownerCiv);
		virtual ~HealthSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}