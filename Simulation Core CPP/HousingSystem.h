#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI HousingSystem : public CivilizationSystem
	{
	public:
		HousingSystem(Civilization* ownerCiv);
		virtual ~HousingSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}