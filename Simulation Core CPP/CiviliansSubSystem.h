#pragma once

#include "DLLExportDefinitions.h"
#include "SimTypes.h"
#include "SocialSubSystem.h"
#include "Civilian.h"

namespace sim
{
	struct SIMAPI CivilianRecord
	{
	public:
		Civilian* civilian;
		double registerDate;		
	};

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
		const CivilianRecord* unregisterCivilian(Civilian* civilian);

	public:
		const IDMap<CivilianRecord>& getCivilianRecords() const;
		const CivilianRecord* getCivilianRecord(const GameID& civID) const;

	public:
		int getInitialPopulationFamilies() const;

	protected:
		virtual void populateSystemConfig(SystemConfigTable* systemConfigTable) override;

	private:
		GameID generateNewID();
		void registerInitialPopulations();

	private:
		IDMap<CivilianRecord> _civilians;

	private:
		int	_initialPopulationFamilies = 2;

	private:
		static GameID _globalCivilianIDCounter;
	};
}
