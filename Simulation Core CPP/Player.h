#pragma once

#include "DLLExportDefinitions.h"
#include "GameEntity.h"
#include "Civilization.h"
#include <string>

namespace sim
{
	enum class PlayerType
	{
		LocalHumanPlayer,
		LANHumanPlayer,
		OnlineHumanPlayer,
		LocalAIPlayer,
		LANAIPlayer,
		OnlineAIPlayer,
		PlayerTypeCount
	};

	class SIMAPI Player : public GameEntity
	{
	public:
		Player(const std::string& playerName, PlayerType playerType);
		virtual ~Player();

	public:
		PlayerType getPlayerType() const;
		const Civilization* getOwnedCivilization() const;
		void setPlayerType(PlayerType playerType);
		void setOwnedCivilization(Civilization* ownedCivilization);

	public:
		virtual bool initialize() override;
		virtual void update(double elapsedDays) override;
		virtual void finalize() override;

	protected:
		PlayerType _playerType;		
		Civilization* _ownedCivilization;
	};
}