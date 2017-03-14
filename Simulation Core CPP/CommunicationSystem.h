#pragma once

#include "DLLExportDefinitions.h"
#include "CivilizationSystem.h"
#include "IPostParticipant.h"
#include "SimTypes.h"
#include <vector>
#include <map>
#include <thread>

namespace sim
{
	struct SIMAPI MessageRecord
	{
	public:
		double sendDate;
		double recieveDate;
		Priority messagePriority;
		IPostParticipant* sender;
		IPostParticipant* reciever;
		Message* content;
	};

	class SIMAPI CommunicationSystem : public CivilizationSystem
	{
	public:
		CommunicationSystem(Civilization* ownerCiv);
		virtual ~CommunicationSystem();

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;

	public:
		void sendMessage(bool isInternal, IPostParticipant* sender, IPostParticipant* reciever, Message* content, Priority messagePriority = Priority::Normal);

	private:		
		GameID generateNewID();
		MessageRecord* getNextMessageRecord();
		void internalProcessingQueue();
		void processMessage(MessageRecord* message);

	private:
		static void processingMessagesThread(CommunicationSystem* commSystem);

	private:
		std::map<Priority, std::vector<MessageRecord>> _messages;
		std::thread _processingThread;
		bool _isActiveCommunications;

	private:
		static GameID _globalMessageIDCounter;
	};
}