#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI ConstructionSystem : public CivilizationSystem
	{
	public:
		ConstructionSystem(Civilization* ownerCiv);
		virtual ~ConstructionSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}