#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI SecuritySystem : public CivilizationSystem
	{
	public:
		SecuritySystem(Civilization* ownerCiv);
		virtual ~SecuritySystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}