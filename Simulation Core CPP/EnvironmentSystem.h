#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI EnvironmentSystem : public CivilizationSystem
	{
	public:
		EnvironmentSystem(Civilization* ownerCiv);
		virtual ~EnvironmentSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}