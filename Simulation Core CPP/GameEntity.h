#pragma once

#include "DLLExportDefinitions.h"
#include <string>

namespace sim
{
	class SIMAPI GameEntity
	{
	public:
		GameEntity();
		GameEntity(const std::string& name);
		virtual ~GameEntity();

	public:
		const std::string& getName() const;
		void setName(const std::string& name);

	public:
		virtual bool initialize() = 0;
		virtual void update(double elapsedDays) = 0;
		virtual void finalize() = 0;

	protected:
		std::string _name;
	};
}
