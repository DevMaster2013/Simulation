#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI DefenseSystem : public CivilizationSystem
	{
	public:
		DefenseSystem(Civilization* ownerCiv);
		virtual ~DefenseSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}