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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}