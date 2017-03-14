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
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}