#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI SupplySystem : public CivilizationSystem
	{
	public:
		SupplySystem(Civilization* ownerCiv);
		virtual ~SupplySystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}