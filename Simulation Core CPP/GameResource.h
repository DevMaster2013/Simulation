#pragma once

#include "DLLExportDefinitions.h"
#include <string>
#include <fstream>

namespace sim
{
	class SIMAPI GameResource
	{
	public:
		GameResource(const std::string& name, const std::string& resourceFileName);
		virtual ~GameResource();

	public:
		bool load();
		bool save();
		void release();

	protected:
		virtual bool onLoad(std::ifstream& fileStream) = 0;
		virtual bool onSave(std::ofstream& fileStream) = 0;
		virtual void onRelease() = 0;

	public:
		const std::string& getName() const;
		const std::string& getResourceFileName() const;
		bool isLoaded() const;
		void setName(const std::string& name);
		void setResourceFileName(const std::string& name);

	protected:
		std::string _name;
		std::string _resourceFileName;
		bool _isLoaded;
	};
}