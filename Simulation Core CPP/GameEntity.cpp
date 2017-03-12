#include "GameEntity.h"

sim::GameEntity::GameEntity()
	: _name("No Name")
{
}

sim::GameEntity::GameEntity(const std::string & name)
	: _name(name)
{
}

sim::GameEntity::~GameEntity()
{
}

const std::string & sim::GameEntity::GetName() const
{
	return _name;
}

void sim::GameEntity::SetName(const std::string & name)
{
	_name = name;
}