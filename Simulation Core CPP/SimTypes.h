#pragma once

#include "HelpfulMacros.h"
#include <map>
#include <string>

namespace sim
{
	using CivilianID = size_t;
	static const CivilianID UNKNOWN_ID = (CivilianID)-1;

	template<typename T>
	using StringMap = std::map<std::string, T>;

	template<typename T>
	using IDMap = std::map<CivilianID, T>;
}
