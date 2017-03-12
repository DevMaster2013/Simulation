#pragma once

#include "HelpfulMacros.h"
#include <map>
#include <string>

namespace sim
{
	template<typename T>
	using StringMap = std::map<std::string, T>;
}
