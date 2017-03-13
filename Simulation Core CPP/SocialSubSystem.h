#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI SocialSystem;
	class SIMAPI SocialSubSystem : public CivilizationSystem
	{
	public:
		SocialSubSystem(Civilization* ownerCiv, SocialSystem* socialSystem, const std::string& name);
		virtual ~SocialSubSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;

	public:
		SocialSystem* GetSocialSystem() const;
	};
}