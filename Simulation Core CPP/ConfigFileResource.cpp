#include "ConfigFileResource.h"
#include "StringHelper.h"

sim::ConfigFileResource::ConfigFileResource(const std::string & name, const std::string & resourceFileName)
	: GameResource(name, resourceFileName)
{
}

sim::ConfigFileResource::~ConfigFileResource()
{
}

bool sim::ConfigFileResource::onLoad(std::ifstream & fileStream)
{
	_systemConfigs.clear();
	std::string line;
	while (!fileStream.eof())
	{
		std::getline(fileStream, line);
		std::string catName;
		if (isCategory(line, catName))
		{
			SystemConfigTable* newConfigTable = new SystemConfigTable();
			_systemConfigs[catName] = newConfigTable;
			do
			{
				std::getline(fileStream, line);
				std::string valueName, value;
				if (parseConfigLine(line, valueName, value))
				{
					newConfigTable->setValue(valueName, value);
				}

			} while (!isCategory(line, catName) && !fileStream.eof());
		}
	}

	return true;
}

bool sim::ConfigFileResource::onSave(std::ofstream & fileStream)
{
	for each (auto& sysConf in _systemConfigs)
	{
		fileStream << "[" << sysConf.first << "]\n";
		const auto& values = sysConf.second->getValueMap();
		for each (const auto& val in values)
		{
			fileStream << val.first << " = " << val.second << "\n";
		}
	}

	return true;
}

void sim::ConfigFileResource::onRelease()
{
	for each (auto& sysConf in _systemConfigs)
	{
		delete sysConf.second;
	}
	_systemConfigs.clear();
}

sim::SystemConfigTable * sim::ConfigFileResource::getConfigTable(const std::string & systemName)
{
	auto found = _systemConfigs.find(systemName);
	if (found != _systemConfigs.end())
		return found->second;

	return nullptr;
}

bool sim::ConfigFileResource::parseConfigLine(const std::string & configLine, std::string & valueName, std::string & value)
{
	auto equalPos = configLine.find('=');
	if (equalPos == configLine.npos)
		return false;

	valueName = StringHelper::trim(StringHelper::mid(configLine, 0, equalPos - 1));
	value = StringHelper::trim(StringHelper::mid(configLine, equalPos + 1, configLine.npos));

	return true;
}

bool sim::ConfigFileResource::isCategory(const std::string & configLine, std::string & catName)
{
	auto startBracket = configLine.find('[');
	auto endBracket = configLine.find(']');
	if (startBracket != configLine.npos && endBracket != configLine.npos)
	{
		catName = StringHelper::mid(configLine, startBracket + 1, endBracket - 1);
		return true;
	}

	catName = "";
	return false;
}
