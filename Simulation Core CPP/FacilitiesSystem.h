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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}