#pragma once

#include "DLLExportDefinitions.h"
#include "SimTypes.h"
#include "SocialSubSystem.h"
#include "Civilian.h"

namespace sim
{
	struct SIMAPI CivilianDieRecord
	{
	public:
		Civilian* civilian;
		double deathDate;
	};

	class SIMAPI DiyingSubSystem : public SocialSubSystem
	{
	public:
		DiyingSubSystem(Civilization* ownerCiv, CivilizationSystem* socialSystem);
		virtual ~DiyingSubSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;

	public:
		void registerNewDeadRecord(Civilian* deadCivilian);

	public:
		const IDMap<CivilianDieRecord>& getCivilianDieRecords() const;
		const CivilianDieRecord* getCivilianDieRecord(const GameID& civID) const;

	protected:
		virtual void populateSystemConfig(SystemConfigTable* systemConfigTable) override;
		virtual void handleMessage(IPostParticipant * sender, Message * message) override;

	private:
		IDMap<CivilianDieRecord> _deads;
	};
}
