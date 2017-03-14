#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI AgricultureSystem : public CivilizationSystem
	{
	public:
		AgricultureSystem(Civilization* ownerCiv);
		virtual ~AgricultureSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}