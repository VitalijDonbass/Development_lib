#pragma once

#include "Loader.h"
#include "../Loger/Loger.h"

namespace dl
{
	class System
	{
	public:
		static TypeError initSystem(int argc, char** argv, TypeOutput tpOutp = TypeOutput::CONSOLE);
		static void unInitSystem();
		static std::string downPach(std::string inputPach);

		static std::string& getRootPach();
		static void setOutputer(TypeOutput tpOut);
		static const Outputer& getOutputer();
	private:
		static bool isInitSystem;
		static std::string pachToRootFolder;
		static Outputer* outputer;

		static void failInitSystem();
		static void process(Log& lg);
	};
}