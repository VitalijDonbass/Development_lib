#pragma once

#include <string>
#include <vector>

namespace dl
{
	enum class TypeLog
	{
		EMPTY_LOG = 0,
	};

	class Log
	{
	public:
		Log(const Log& obj);
		Log(std::string messg = "", TypeLog tpLog = TypeLog::EMPTY_LOG, bool isEx = false);

		Log& operator=(const Log& obj);

		std::string message;
		TypeLog typeLog;
		bool isException;
	};

	class IOutputer
	{
	public:
		IOutputer(const IOutputer& obj) = delete;
		IOutputer();

		IOutputer& operator=(const IOutputer& obj) = delete;

		virtual void output(Log& lgs) = 0;
	protected:
		static std::string TypeLogName[];
	};

	class ConsoleOutputer : public IOutputer
	{
	public:
		ConsoleOutputer(const ConsoleOutputer& obj) = delete;
		ConsoleOutputer();

		ConsoleOutputer& operator=(const ConsoleOutputer& obj) = delete;

		void output(Log& lgs) override;
	};

	class Loger
	{
	public:
		Loger(const Loger& obj) = delete;
		Loger();

		Loger& operator=(const Loger& obj) = delete;

		void addLog(std::string messg = "", TypeLog tpLog = TypeLog::EMPTY_LOG, bool isEx = false);

		void process();
		void process(IOutputer& otp);
		void process(std::string messg, TypeLog tpLog, bool isEx);
		void process(std::string messg, TypeLog tpLog, bool isEx, IOutputer& otp);
	private:
		std::vector<Log> logs;
	};
}