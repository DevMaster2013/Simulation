#pragma once
#include "DLLExportDefinitions.h"
#include <string>

namespace sim
{
	class SIMAPI StringHelper
	{
	public:
		static std::string trim(const std::string& value);
		static std::string mid(const std::string& value, size_t start = 0, size_t end = std::string::npos);
	};
}
