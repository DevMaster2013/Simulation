#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI DiplomacySystem : public CivilizationSystem
	{
	public:
		DiplomacySystem(Civilization* ownerCiv);
		virtual ~DiplomacySystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}