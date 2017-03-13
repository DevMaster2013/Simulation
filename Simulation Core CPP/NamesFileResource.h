#pragma once

#include "DLLExportDefinitions.h"
#include "GameResource.h"
#include <vector>

namespace sim
{
	class SIMAPI NamesFileResource : public GameResource
	{
	public:
		NamesFileResource(const std::string& name, const std::string& resourceFileName);
		virtual ~NamesFileResource();

	public:
		virtual bool onLoad(std::ifstream & fileStream) override;
		virtual bool onSave(std::ofstream & fileStream) override;
		virtual void onRelease() override;

	public:
		void AddName(const std::string& name);
		void RemoveName(const std::string& name);

	public:
		const std::vector<std::string>& GetNamesList() const;

	private:
		std::vector<std::string> _namesList;
	};
}
