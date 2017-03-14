#pragma once

#include "DLLExportDefinitions.h"
#include "Message.h"
#include "Civilian.h"

namespace sim
{
	class SIMAPI CivilianDeadMessage : public Message
	{
	public:
		CivilianDeadMessage(Civilian* civilian);
		virtual ~CivilianDeadMessage();

	public:
		Civilian* getCivilian() const;
		void setCivilian(Civilian* civilian);

	private:
		Civilian* _deadCivilian;
	};
}
