#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI FinancialSystem : public CivilizationSystem
	{
	public:
		FinancialSystem(Civilization* ownerCiv);
		virtual ~FinancialSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}