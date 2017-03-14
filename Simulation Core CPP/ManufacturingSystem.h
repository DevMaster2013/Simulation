#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI ManufacturingSystem : public CivilizationSystem
	{
	public:
		ManufacturingSystem(Civilization* ownerCiv);
		virtual ~ManufacturingSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}