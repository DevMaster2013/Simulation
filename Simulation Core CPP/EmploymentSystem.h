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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}