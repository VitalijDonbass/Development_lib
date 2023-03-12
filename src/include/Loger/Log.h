#pragma once

#include <string>

namespace dl
{
	enum class TypeLog
	{
		MESSAGE,
		WARNING,
		ERROR,
	};

	enum class TypeOutput
	{
		CONSOLE,
		UI,
	};

	enum class TypeWarning
	{
		EMPTY_WARNING = 0,
		DATA_LOSS = -1,
		COLISION = -2,
	};
	const std::string warningsName[]{
		"EMPTY WARNING",
		"DATA LOSS",
		"COLISION",
	};

	enum class TypeError
	{
		EMPTY_ERROR = 0,
		FAIL_LOAD = -1,
		FAIL_FIND_FILE = -2,
		FAIL_INIT = -3,
		COLISION = -4,
	};
	const std::string errorsName[] = {
		"EMPTY ERROR",
		"FAIL LOAD",
		"FAIL FIND FILE",
		"FAIL INIT",
		"COLISION",
	};

	class Log
	{
	public:
		Log& operator=(const Log& lg);
		Log(const Log& lg);
		Log(TypeLog tpLg);
		virtual ~Log();

		virtual TypeLog getTypeLog();
		virtual void process();
	private:
		TypeLog typeLog;
	};

	class Message : public Log
	{
	public:
		Message& operator=(const Message& lg);
		Message(const Message& lg);
		Message(std::string messg = "");

		std::string message;
	};

	class Warning : public Log
	{
	public:
		Warning& operator=(const Warning& lg);
		Warning(const Warning& lg);
		Warning(TypeWarning tpWrg = TypeWarning::EMPTY_WARNING, std::string messg = "");

		TypeWarning typeWarning;
		std::string message;
	};

	class Error : public Log
	{
	public:
		Error& operator=(const Error& lg);
		Error(const Error& lg);
		Error(TypeError tpErr = TypeError::EMPTY_ERROR, std::string messg = "", bool isExc = false);

		void process() override;

		TypeError typeError;
		std::string message;
		bool isException;
	};
}