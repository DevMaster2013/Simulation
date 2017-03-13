#pragma once

#include "DLLExportDefinitions.h"
#include <string>
#include <vector>

namespace sim
{
	class SIMAPI FileSystemHelper
	{
	public:
		static std::vector<std::string> GetFilesInDirectory(const std::string& path, const std::string& pattern = "*.*");
		static std::string GetFileNameWithoutPath(const std::string& filePath);
		static std::string GetFileNameWithoutExtension(const std::string& filePath);
		static std::string GetExtension(const std::string& filePath);
	};
}
