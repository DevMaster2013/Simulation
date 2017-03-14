#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI EntertainmentSystem : public CivilizationSystem
	{
	public:
		EntertainmentSystem(Civilization* ownerCiv);
		virtual ~EntertainmentSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}