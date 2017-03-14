#include "CivilianDeadMessage.h"

sim::CivilianDeadMessage::CivilianDeadMessage(Civilian * civilian)
	: Message()
	, _deadCivilian(civilian)
{
	_messageTypeID = MessageTypeID::CivilianDeadMessage;
}

sim::CivilianDeadMessage::~CivilianDeadMessage()
{
}

sim::Civilian * sim::CivilianDeadMessage::getCivilian() const
{
	return _deadCivilian;
}

void sim::CivilianDeadMessage::setCivilian(Civilian * civilian)
{
	_deadCivilian = civilian;
}
