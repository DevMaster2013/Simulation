#pragma once

#include "DLLExportDefinitions.h"
#include "GameResource.h"
#include "SystemConfigTable.h"

namespace sim
{
	class SIMAPI ConfigFileResource : public GameResource
	{
	public:
		ConfigFileResource(const std::string& name, const std::string& resourceFileName);
		virtual ~ConfigFileResource();

	public:
		virtual bool onLoad(std::ifstream & fileStream) override;
		virtual bool onSave(std::ofstream & fileStream) override;
		virtual void onRelease() override;

	public:
		SystemConfigTable* GetConfigTable(const std::string& systemName);

	private:
		bool parseConfigLine(const std::string& configLine, std::string& valueName, std::string& value);
		bool isCategory(const std::string& configLine, std::string& catName);

	private:
		StringMap<SystemConfigTable*> _systemConfigs;
	};
}