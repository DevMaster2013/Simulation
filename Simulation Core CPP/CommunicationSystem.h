#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI CommunicationSystem : public CivilizationSystem
	{
	public:
		CommunicationSystem(Civilization* ownerCiv);
		virtual ~CommunicationSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;
	};
}