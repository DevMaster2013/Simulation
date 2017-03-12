#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI ForeignersSystem : public CivilizationSystem
	{
	public:
		ForeignersSystem(Civilization* ownerCiv);
		virtual ~ForeignersSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}