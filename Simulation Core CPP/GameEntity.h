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
		const std::string& GetName() const;
		void SetName(const std::string& name);

	public:
		virtual bool Initialize() = 0;
		virtual void Update(double elapsedDays) = 0;
		virtual void Finalize() = 0;

	protected:
		std::string _name;
	};
}
