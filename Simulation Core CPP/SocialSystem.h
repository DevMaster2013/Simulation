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
			double	MaximumAge = 100.0;
		};

	public:
		SocialSystem(Civilization* ownerCiv);
		virtual ~SocialSystem();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;

	public:
		const Config& GetSystemConfig() const;

	protected:
		virtual void populateSystemConfig(SystemConfigTable* systemConfigTable) override;

	private:
		Config _socialConfig;
	};
}