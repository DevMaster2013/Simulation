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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}