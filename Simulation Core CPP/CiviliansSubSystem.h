#pragma once

#include "DLLExportDefinitions.h"
#include "SocialSubSystem.h"

namespace sim
{
	class SIMAPI CivilianSubSystem : public SocialSubSystem
	{
	public:
		CivilianSubSystem(Civilization* ownerCiv, SocialSystem* socialSystem);
		virtual ~CivilianSubSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;
	};
}
