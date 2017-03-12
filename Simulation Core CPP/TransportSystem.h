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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}