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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}