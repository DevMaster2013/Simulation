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

const std::string & sim::GameEntity::getName() const
{
	return _name;
}

void sim::GameEntity::setName(const std::string & name)
{
	_name = name;
}