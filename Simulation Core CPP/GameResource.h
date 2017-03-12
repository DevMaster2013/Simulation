#pragma once

#include "DLLExportDefinitions.h"
#include <string>
#include <fstream>

namespace sim
{
	class SIMAPI GameResource
	{
	public:
		GameResource(const std::string& name);
		virtual ~GameResource();

	public:
		bool Load(const std::string& resourceFileName);
		bool Save(const std::string& resourceFileName);

	protected:
		virtual bool onLoad(std::ifstream& fileStream) = 0;
		virtual bool onSave(std::ofstream& fileStream) = 0;

	public:
		const std::string& GetName() const;
		void SetName(const std::string& name);

	protected:
		std::string _name;
	};
}