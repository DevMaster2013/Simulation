#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI ResourcesSystem : public CivilizationSystem
	{
	public:
		ResourcesSystem(Civilization* ownerCiv);
		virtual ~ResourcesSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}