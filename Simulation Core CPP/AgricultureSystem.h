#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI AgricultureSystem : public CivilizationSystem
	{
	public:
		AgricultureSystem(Civilization* ownerCiv);
		virtual ~AgricultureSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}