#pragma once

#include "DLLExportDefinitions.h"
#include "SimTypes.h"
#include "MessageTypes.h"

namespace sim
{
	class SIMAPI Message
	{
	public:
		Message();
		virtual ~Message();

	public:
		const MessageTypeID& getMessageTypeID() const;
		const GameID& getMessageID() const;
		void setMessageTypeID(const MessageTypeID& typeID);
		void setMessageID(const GameID& messageID);

	protected:
		GameID _messageID;
		MessageTypeID _messageTypeID;
	};
}
