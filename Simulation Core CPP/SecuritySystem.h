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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}