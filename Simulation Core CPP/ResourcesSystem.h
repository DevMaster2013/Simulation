#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI ResourcesSystem : public CivilizationSystem
	{
	public:
		ResourcesSystem(Civilization* ownerCiv);
		virtual ~ResourcesSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}