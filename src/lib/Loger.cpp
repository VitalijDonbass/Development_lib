#include "../include/Loger.h"
#include <iostream>

std::string IOutputer::TypeLogName[] =
{
	"empty log",
};

Log::Log(const Log& obj)
	:typeLog(obj.typeLog), message(obj.message), isException(obj.isException)
{
}

Log::Log(std::string messg, TypeLog tpLog, bool isEx)
	:typeLog(tpLog), message(messg), isException(isEx)
{
}

Log& Log::operator=(const Log& obj)
{
	this->isException = obj.isException;
	this->message = obj.message;
	this->typeLog = obj.typeLog;
	return *this;
}

IOutputer::IOutputer()
{
}

ConsoleOutputer::ConsoleOutputer()
	: IOutputer()
{
}

void ConsoleOutputer::output(Log& lgs)
{
	std::cout << "Log type: " << (int)lgs.typeLog <<
		"(" << this->TypeLogName[-(int)lgs.typeLog] <<
		") " << lgs.message << (lgs.isException ? " = exception" : "") << std::endl;
}

Loger::Loger()
	:logs(std::vector<Log>())
{
}

void Loger::addLog(std::string messg, TypeLog tpLog, bool isEx)
{
	this->logs.push_back(Log(messg, tpLog, isEx));
}

void Loger::process()
{
	for (Log& log : this->logs)
	{
		if (log.isException) throw log.typeLog;
	}
}

void Loger::process(IOutputer& otp)
{
	for (Log& log : this->logs)
	{
		otp.output(log);
		if (log.isException) throw log.typeLog;
	}
}

void Loger::process(std::string messg, TypeLog tpLog, bool isEx)
{
	Log log(messg, tpLog, isEx);
	if (log.isException) throw log.typeLog;
}

void Loger::process(std::string messg, TypeLog tpLog, bool isEx, IOutputer& otp)
{
	Log log(messg, tpLog, isEx);
	otp.output(log);
	if (log.isException) throw log.typeLog;
}
