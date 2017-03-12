#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI PoliticsSystem : public CivilizationSystem
	{
	public:
		PoliticsSystem(Civilization* ownerCiv);
		virtual ~PoliticsSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}