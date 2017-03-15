#include "Player.h"

sim::Player::Player(const std::string & playerName, PlayerType playerType)
	: GameEntity(playerName)
	, _playerType(playerType)
	, _ownedCivilization(nullptr)
{
}

sim::Player::~Player()
{
}

sim::PlayerType sim::Player::getPlayerType() const
{
	return _playerType;
}

const sim::Civilization * sim::Player::getOwnedCivilization() const
{
	return _ownedCivilization;
}

void sim::Player::setPlayerType(PlayerType playerType)
{
	_playerType = playerType;
}

void sim::Player::setOwnedCivilization(Civilization * ownedCivilization)
{
	_ownedCivilization = ownedCivilization;
}

bool sim::Player::initialize()
{
	return true;
}

void sim::Player::update(double /*elapsedDays*/)
{
}

void sim::Player::finalize()
{
}
