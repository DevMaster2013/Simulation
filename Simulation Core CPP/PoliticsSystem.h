#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI PoliticsSystem : public CivilizationSystem
	{
	public:
		PoliticsSystem(Civilization* ownerCiv);
		virtual ~PoliticsSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}