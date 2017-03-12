#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI TradeSystem : public CivilizationSystem
	{
	public:
		TradeSystem(Civilization* ownerCiv);
		virtual ~TradeSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}