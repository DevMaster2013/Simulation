#pragma once

#include "DLLExportDefinitions.h"
#include <string>

namespace sim
{
	class SIMAPI SimException
	{
	public:
		SimException();
		SimException(const std::string& message);
		virtual ~SimException();

	public:
		const std::string& GetMessage() const;

	protected:
		std::string _errMessage;
	};
}