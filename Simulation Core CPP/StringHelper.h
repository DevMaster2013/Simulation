#pragma once
#include "DLLExportDefinitions.h"
#include <string>

namespace sim
{
	class SIMAPI StringHelper
	{
	public:
		static std::string Trim(const std::string& value);
		static std::string Mid(const std::string& value, size_t start = 0, size_t end = std::string::npos);
	};
}
