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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}