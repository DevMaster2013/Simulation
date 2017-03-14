#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI ReligionSystem : public CivilizationSystem
	{
	public:
		ReligionSystem(Civilization* ownerCiv);
		virtual ~ReligionSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}