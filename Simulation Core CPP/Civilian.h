#pragma once

#include "DLLExportDefinitions.h"
#include "GameEntity.h"
#include <string>
namespace sim
{
	enum class CivilianSex : int { Male, Female };

	class SIMAPI Civilian : public GameEntity
	{
	public:
		Civilian(const std::string& name);
		virtual ~Civilian();

	public:
		virtual bool Initialize() override;
		virtual void Update(double elapsedDays) override;
		virtual void Finalize() override;

	public:
		CivilianSex GetSex() const;
		void SetSex(CivilianSex sex);

	protected:
		CivilianSex _civilianSex;
	};
}
