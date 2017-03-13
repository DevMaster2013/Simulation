#pragma once

#include "DLLExportDefinitions.h"
#include "SimTypes.h"
#include <sstream>

namespace sim
{
	class SIMAPI SystemConfigTable
	{
	public:
		SystemConfigTable();
		~SystemConfigTable();

	public:
		template<typename T>
		T GetValue(const std::string& valueName);

		template<typename T>
		void SetValue(const std::string& valueName, const T& value);

	public:
		std::string GetStringValue(const std::string& valueName);
		void SetStringValue(const std::string& valueName, const std::string& value);
		const StringMap<std::string>& GetValueMap() const;

	private:
		StringMap<std::string> _configEntries;		
	};

	template<typename T>
	inline T SystemConfigTable::GetValue(const std::string & valueName)
	{
		T value;
		std::stringstream str(GetStringValue(valueName));
		str >> value;
		return value;
	}

	template<typename T>
	inline void SystemConfigTable::SetValue(const std::string & valueName, const T & value)
	{
		std::stringstream str;
		str << value;
		SetStringValue(valueName, str.str());
	}
}