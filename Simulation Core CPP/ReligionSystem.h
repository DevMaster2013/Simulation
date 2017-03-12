#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI ReligionSystem : public CivilizationSystem
	{
	public:
		ReligionSystem(Civilization* ownerCiv);
		virtual ~ReligionSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}