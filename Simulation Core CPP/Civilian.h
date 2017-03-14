#pragma once

#include "DLLExportDefinitions.h"
#include "SimTypes.h"
#include "GameEntity.h"
#include <string>
namespace sim
{
	enum class CivilianSex : int { Male, Female };

	class Civilization;
	class SIMAPI Civilian : public GameEntity
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
		const CivilianID& getCivilianID() const;
		void setSex(CivilianSex sex);
		void setHomeCivilization(Civilization* homeCiv);
		void setCivilianID(const CivilianID& newID);

	protected:
		CivilianID _civID;
		CivilianSex _civilianSex;
		Civilization* _homeCivilization;
	};
}
