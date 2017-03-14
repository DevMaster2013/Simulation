#pragma once

#include "DLLExportDefinitions.h"
#include "Message.h"

namespace sim
{
	class SIMAPI IPostParticipant
	{
	public:
		virtual void handleMessage(IPostParticipant* sender, Message* message) = 0;
	};
}