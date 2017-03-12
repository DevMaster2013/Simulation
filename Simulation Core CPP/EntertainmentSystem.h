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
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}