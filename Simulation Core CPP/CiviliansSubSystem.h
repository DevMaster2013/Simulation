#pragma once

#include "DLLExportDefinitions.h"
#include "SimTypes.h"
#include "SocialSubSystem.h"
#include "Civilian.h"

namespace sim
{
	class SIMAPI CiviliansSubSystem : public SocialSubSystem
	{
	public:
		CiviliansSubSystem(Civilization* ownerCiv, CivilizationSystem* socialSystem);
		virtual ~CiviliansSubSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;

	public:
		void registerNewCivilian(Civilian* newCivilian);

	public:
		int getInitialPopulationFamilies() const;
		double getMaximumAge() const;

	protected:
		virtual void populateSystemConfig(SystemConfigTable* systemConfigTable) override;

	private:
		CivilianID generateNewID();
		void registerInitialPopulations();

	private:
		IDMap<Civilian*> _civilians;			

	private:
		int		_initialPopulationFamilies = 2;
		double	_maximumAge = 100.0;

	private:
		static CivilianID _globalCivilianIDCounter;
	};
}
