#pragma once

#ifdef SIMULATIONCORECPP_EXPORTS
#define SIMAPI __declspec(dllexport)
#else
#define SIMAPI __declspec(dllimport)
#endif

#pragma warning( disable : 4251)