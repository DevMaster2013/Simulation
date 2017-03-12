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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}