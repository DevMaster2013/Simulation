#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI ForeignersSystem : public CivilizationSystem
	{
	public:
		ForeignersSystem(Civilization* ownerCiv);
		virtual ~ForeignersSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}