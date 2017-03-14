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
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}