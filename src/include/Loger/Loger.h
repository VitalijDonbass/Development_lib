#pragma once

#include <string>
#include <vector>
#include "Outputer.h"

namespace dl
{
	class Loger
	{
	public:
		static void addLog(Log& lg);

		static void process(Log& lg);
		static void process(Log& lg, const Outputer& outp);
		static void process();
		static void process(const Outputer& outp);
	private:
		static std::vector<Log*> logs;
	};
}