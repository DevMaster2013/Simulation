#pragma once

#include "DLLExportDefinitions.h"
#include "SimTypes.h"
#include "GameEntity.h"
#include "IPostParticipant.h"
#include <string>

namespace sim
{
	enum class CivilianSex : int { Male, Female };

	class Civilization;
	class SIMAPI Civilian : public GameEntity, public IPostParticipant
	{
	public:
		Civilian(Civilization* civilization, const std::string& name);
		virtual ~Civilian();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;

	public:
		CivilianSex getSex() const;
		Civilization* getHomeCivilization() const;
		const GameID& getCivilianID() const;
		double getAge() const;
		void setSex(CivilianSex sex);
		void setHomeCivilization(Civilization* homeCiv);
		void setCivilianID(const GameID& newID);
		void setAge(double newAge);

	protected:
		virtual void handleMessage(IPostParticipant * sender, Message * message) override;

	protected:
		GameID _civID;
		CivilianSex _civilianSex;
		Civilization* _homeCivilization;
		double _age;
		double _estimatedDieAge;
	};
}
