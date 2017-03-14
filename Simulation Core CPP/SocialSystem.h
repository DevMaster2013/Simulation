#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"

namespace sim
{
	class SIMAPI SocialSystem : public CivilizationSystem
	{
	public:
		struct Config
		{
		public:
			int		MaximumNumberOfChildren = 2;
			double	MinimumManMarriageAge = 16.0;
			double	MinimumWomanMarriageAge = 16.0;
		};

	public:
		SocialSystem(Civilization* ownerCiv);
		virtual ~SocialSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;

	protected:
		virtual void populateSystemConfig(SystemConfigTable* systemConfigTable) override;
		virtual void handleMessage(IPostParticipant * sender, Message * message) override;
	};
}