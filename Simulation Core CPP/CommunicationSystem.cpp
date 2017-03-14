#include "CommunicationSystem.h"
#include "Game.h"

sim::GameID sim::CommunicationSystem::_globalMessageIDCounter = 1;

sim::CommunicationSystem::CommunicationSystem(Civilization* ownerCiv)
	: CivilizationSystem(ownerCiv, nullptr, "CommunicationSystem")
	, _isActiveCommunications(false)
{
}

sim::CommunicationSystem::~CommunicationSystem()
{
}

bool sim::CommunicationSystem::initialize()
{
	if (!sim::CivilizationSystem::initialize())
		return false;

	// Craete the processing thread
	_processingThread = std::thread(sim::CommunicationSystem::processingMessagesThread, this);
	_isActiveCommunications = true;

	return true;
}

void sim::CommunicationSystem::update(double elapsedDays)
{
	sim::CivilizationSystem::update(elapsedDays);
}

void sim::CommunicationSystem::finalize()
{
	// stop the thread
	_isActiveCommunications = false;
	_processingThread.join();

	// remove the messages
	for each (auto& messageQueue in _messages)
	{
		for each (auto& messageRecord in messageQueue.second)
		{
			delete messageRecord.content;
		}
		_messages[messageQueue.first].clear();
	}
	_messages.clear();

	sim::CivilizationSystem::finalize();
}

void sim::CommunicationSystem::sendMessage(bool /*isInternal*/, IPostParticipant * sender, IPostParticipant * reciever, Message * content, Priority messagePriority)
{
	// Create new message record
	MessageRecord record;	
	record.messagePriority = messagePriority;
	record.sendDate = Game::getInstance()->getGameClock().getCurrentGameTime();
	record.sender = sender;
	record.reciever = reciever;
	record.content = content;
	content->setMessageID(generateNewID());

	// add the record
	auto messageQueue = _messages.find(messagePriority);
	if (messageQueue == _messages.end())
		_messages[messagePriority] = std::vector<MessageRecord>();
	_messages[messagePriority].push_back(record);
}

sim::GameID sim::CommunicationSystem::generateNewID()
{
	return _globalMessageIDCounter++;
}

sim::MessageRecord* sim::CommunicationSystem::getNextMessageRecord()
{
	// loop on the priorities
	int prioritiesCritical = (int)Priority::ProioritiesCount - 1;
	for (int curPriority = prioritiesCritical; curPriority >= 0; curPriority--)
	{
		Priority pri = (Priority)curPriority;
		auto messageQueue = _messages.find(pri);
		if (messageQueue != _messages.end())
		{
			auto& messages = messageQueue->second;
			if (messages.size() > 0)
			{
				auto& messageRecord = messages[0];
				messages.erase(messages.begin());
				return &messageRecord;
			}
		}
	}

	return nullptr;
}

void sim::CommunicationSystem::internalProcessingQueue()
{
	while (_isActiveCommunications)
	{
		auto nextMessage = getNextMessageRecord();
		if (nextMessage != nullptr)
		{
			processMessage(nextMessage);
		}
	}
}

void sim::CommunicationSystem::processMessage(MessageRecord * message)
{
	message->reciever->handleMessage(message->sender, message->content);
}

void sim::CommunicationSystem::processingMessagesThread(CommunicationSystem* commSystem)
{
	commSystem->internalProcessingQueue();
}
