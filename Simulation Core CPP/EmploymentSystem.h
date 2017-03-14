#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI EmploymentSystem : public CivilizationSystem
	{
	public:
		EmploymentSystem(Civilization* ownerCiv);
		virtual ~EmploymentSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}