#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI EducationSystem : public CivilizationSystem
	{
	public:
		EducationSystem(Civilization* ownerCiv);
		virtual ~EducationSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}