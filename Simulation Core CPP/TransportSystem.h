#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI TransportSystem : public CivilizationSystem
	{
	public:
		TransportSystem(Civilization* ownerCiv);
		virtual ~TransportSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}