#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI SocialSystem;
	class SIMAPI SocialSubSystem : public CivilizationSystem
	{
	public:
		SocialSubSystem(Civilization* ownerCiv, CivilizationSystem* socialSystem, const std::string& name);
		virtual ~SocialSubSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;

	public:
		SocialSystem* getSocialSystem() const;
	};
}