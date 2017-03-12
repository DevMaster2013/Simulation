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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}