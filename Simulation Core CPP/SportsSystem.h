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
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}