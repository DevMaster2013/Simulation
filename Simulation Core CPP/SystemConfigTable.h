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
		T getValue(const std::string& valueName);

		template<typename T>
		void setValue(const std::string& valueName, const T& value);

	public:
		std::string getStringValue(const std::string& valueName);
		void setStringValue(const std::string& valueName, const std::string& value);
		const StringMap<std::string>& getValueMap() const;

	private:
		StringMap<std::string> _configEntries;		
	};

	template<typename T>
	inline T SystemConfigTable::getValue(const std::string & valueName)
	{
		T value;
		std::stringstream str(getStringValue(valueName));
		str >> value;
		return value;
	}

	template<typename T>
	inline void SystemConfigTable::setValue(const std::string & valueName, const T & value)
	{
		std::stringstream str;
		str << value;
		setStringValue(valueName, str.str());
	}
}