#include "../../include/Loger/Outputer.h"
#include <iostream>

bool dl::Outputer::isCreate

namespace dl
{
	void Outputer::output(Log& lg) const
	{
		switch (lg.getTypeLog())
		{
		case TypeLog::MESSAGE: { this->outputMessage(static_cast<Message&>(lg)); }break;
		case TypeLog::WARNING: { this->outputWarning(static_cast<Warning&>(lg)); }break;
		case TypeLog::ERROR: { this->outputError(static_cast<Error&>(lg)); }break;
		}
	}

	Outputer::~Outputer()
	{
	}

	void ConsoleOutputer::outputMessage(const Message& mssg) const
	{
		std::cout << "Message: " << mssg.message << std::endl;
	}
	void ConsoleOutputer::outputWarning(const Warning& wrn) const
	{
		std::cout << "Warning: " << "[" << warningsName[-(int)wrn.typeWarning] <<
			"] " << wrn.message << std::endl;
	}
	void ConsoleOutputer::outputError(const Error& err) const
	{
		std::cout << "Error: " << "[" << errorsName[-(int)err.typeError] <<
			"] " << err.message << (err.isException ? " = fatal" : "") << std::endl;
	}

	void UIOutputer::outputMessage(const Message& mssg) const
	{
	}
	void UIOutputer::outputWarning(const Warning& wrn) const
	{
	}
	void UIOutputer::outputError(const Error& err) const
	{
	}
}