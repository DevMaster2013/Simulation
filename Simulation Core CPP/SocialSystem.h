#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI SocialSystem : public CivilizationSystem
	{
	public:
		SocialSystem(Civilization* ownerCiv);
		virtual ~SocialSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}