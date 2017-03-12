#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI SportsSystem : public CivilizationSystem
	{
	public:
		SportsSystem(Civilization* ownerCiv);
		virtual ~SportsSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}