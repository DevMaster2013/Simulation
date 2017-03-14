#pragma once

#include "HelpfulMacros.h"
#include <map>
#include <string>

namespace sim
{
	enum class Priority : int { Low, Normal, High, VeryHigh, Critical, ProioritiesCount };

	using GameID = size_t;
	static const GameID UNKNOWN_ID = (GameID)-1;

	template<typename T>
	using StringMap = std::map<std::string, T>;

	template<typename T>
	using IDMap = std::map<GameID, T>;
}
