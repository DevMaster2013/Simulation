#include "Message.h"

sim::Message::Message()
	: _messageID(UNKNOWN_ID)
	, _messageTypeID(MessageTypeID::UnknownType)
{
}

sim::Message::~Message()
{
}

const sim::MessageTypeID & sim::Message::getMessageTypeID() const
{
	return _messageTypeID;
}

const sim::GameID & sim::Message::getMessageID() const
{
	return _messageID;
}

void sim::Message::setMessageTypeID(const MessageTypeID & typeID)
{
	_messageTypeID = typeID;
}

void sim::Message::setMessageID(const GameID & messageID)
{
	_messageID = messageID;
}
