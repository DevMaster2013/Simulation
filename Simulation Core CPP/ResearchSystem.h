#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI ResearchSystem : public CivilizationSystem
	{
	public:
		ResearchSystem(Civilization* ownerCiv);
		virtual ~ResearchSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}