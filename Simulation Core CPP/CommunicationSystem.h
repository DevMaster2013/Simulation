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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}