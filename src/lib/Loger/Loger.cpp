#include <iostream>
#include "../../include/Loger/Loger.h"

std::vector<dl::Log*> dl::Loger::logs;

void dl::Loger::addLog(dl::Log& lg)
{
	switch (lg.getTypeLog())
	{
		case TypeLog::MESSAGE: { Loger::logs.push_back(new Message(static_cast<Message&>(lg))); }break;
		case TypeLog::WARNING: { Loger::logs.push_back(new Warning(static_cast<Warning&>(lg))); }break;
		case TypeLog::ERROR: { Loger::logs.push_back(new Error(static_cast<Error&>(lg))); }break;
	}
}

void dl::Loger::process(dl::Log& lg)
{
	lg.process();
}

void dl::Loger::process(dl::Log& lg, const Outputer& outp)
{
	outp.output(lg);
	lg.process();
}

void dl::Loger::process()
{
	for (auto& log : Loger::logs)
	{
		log->process();
		delete log;
	}
	Loger::logs.clear();
}

void dl::Loger::process(const Outputer& outp)
{
	for (auto& log : Loger::logs)
	{
		outp.output(*log);
		log->process();
		delete log;
	}
	Loger::logs.clear();
}
