#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI EnvironmentSystem : public CivilizationSystem
	{
	public:
		EnvironmentSystem(Civilization* ownerCiv);
		virtual ~EnvironmentSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}