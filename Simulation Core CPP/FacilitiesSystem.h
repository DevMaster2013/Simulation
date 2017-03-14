#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI FacilitiesSystem : public CivilizationSystem
	{
	public:
		FacilitiesSystem(Civilization* ownerCiv);
		virtual ~FacilitiesSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}