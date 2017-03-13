#include "Civilian.h"

sim::Civilian::Civilian(const std::string & name)
	: GameEntity(name)
{
}

sim::Civilian::~Civilian()
{
}

bool sim::Civilian::Initialize()
{
	return true;
}

void sim::Civilian::Update(double elapsedDays)
{
}

void sim::Civilian::Finalize()
{
}

sim::CivilianSex sim::Civilian::GetSex() const
{
	return _civilianSex;
}

void sim::Civilian::SetSex(CivilianSex sex)
{
	_civilianSex = sex;
}
