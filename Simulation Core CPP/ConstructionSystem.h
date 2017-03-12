#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI ConstructionSystem : public CivilizationSystem
	{
	public:
		ConstructionSystem(Civilization* ownerCiv);
		virtual ~ConstructionSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}