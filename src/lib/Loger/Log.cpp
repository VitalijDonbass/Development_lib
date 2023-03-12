#include "../../include/Loger/Log.h"

namespace dl
{
	Log& Log::operator=(const Log& lg)
	{
		this->typeLog = lg.typeLog;
		return *this;
	}

	Log::Log(const Log& lg)
		:typeLog(lg.typeLog)
	{
	}

	Log::Log(TypeLog tpLg)
		:typeLog(tpLg)
	{
	}

	Log::~Log()
	{
	}

	TypeLog Log::getTypeLog()
	{
		return this->typeLog;
	}

	void dl::Log::process()
	{
	}

	Message& Message::operator=(const Message& lg)
	{
		this->message = lg.message;
		return *this;
	}

	dl::Message::Message(const Message& lg)
		:Log(TypeLog::MESSAGE), message(lg.message)
	{
	}

	dl::Message::Message(std::string messg)
		:Log(TypeLog::MESSAGE), message(messg)
	{
	}


	Warning& Warning::operator=(const Warning& lg)
	{
		this->message = lg.message;
		this->typeWarning = lg.typeWarning;
		return *this;
	}

	Warning::Warning(const Warning& lg)
		:Log(TypeLog::WARNING), message(lg.message), typeWarning(lg.typeWarning)
	{
	}

	Warning::Warning(TypeWarning tpWrg, std::string messg)
		:Log(TypeLog::WARNING), message(messg), typeWarning(tpWrg)
	{
	}

	Error& Error::operator=(const Error& lg)
	{
		this->isException = lg.isException;
		this->message = lg.message;
		this->typeError = lg.typeError;
		return *this;
	}

	Error::Error(const Error& lg)
		:Log(TypeLog::ERROR), isException(lg.isException), message(lg.message), typeError(lg.typeError)
	{
	}

	Error::Error(TypeError tpErr, std::string messg, bool isExc)
		:Log(TypeLog::ERROR), isException(isExc), message(messg), typeError(tpErr)
	{
	}

	void Error::process()
	{
		if (this->isException) throw this->typeError;
	}
}