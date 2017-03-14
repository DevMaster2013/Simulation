#pragma once

#include "DLLExportDefinitions.h"
#include <string>
#include <vector>

namespace sim
{
	class SIMAPI FileSystemHelper
	{
	public:
		static std::vector<std::string> getFilesInDirectory(const std::string& path, const std::string& pattern = "*.*");
		static std::string getFileNameWithoutPath(const std::string& filePath);
		static std::string getFileNameWithoutExtension(const std::string& filePath);
		static std::string getExtension(const std::string& filePath);
	};
}
