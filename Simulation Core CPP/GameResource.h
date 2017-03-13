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
		bool Load();
		bool Save();
		void Release();

	protected:
		virtual bool onLoad(std::ifstream& fileStream) = 0;
		virtual bool onSave(std::ofstream& fileStream) = 0;
		virtual void onRelease() = 0;

	public:
		const std::string& GetName() const;
		const std::string& GetResourceFileName() const;
		bool IsLoaded() const;
		void SetName(const std::string& name);
		void SetResourceFileName(const std::string& name);

	protected:
		std::string _name;
		std::string _resourceFileName;
		bool _isLoaded;
	};
}