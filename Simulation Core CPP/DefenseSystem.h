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
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}