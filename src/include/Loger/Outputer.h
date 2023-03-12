#pragma once

#include "Log.h"
#include <vector>

namespace dl
{
	class Outputer
	{
	public:

		virtual ~Outputer();

		virtual void output(Log& lg) const;
	private:
		Outputer operator=(const Outputer& obj) = delete;
		Outputer(const Outputer& obj) = delete;
	protected:
		virtual void outputMessage(const Message& mssg) const = 0;
		virtual void outputWarning(const Warning& wrn) const = 0;
		virtual void outputError(const Error& err) const = 0;
	};

	class ConsoleOutputer : public Outputer
	{
	private:
		ConsoleOutputer operator=(const ConsoleOutputer& obj) = delete;
		ConsoleOutputer(const ConsoleOutputer& obj) = delete;

		void outputMessage(const Message& mssg) const override;
		void outputWarning(const Warning& wrn) const override;
		void outputError(const Error& err) const override;
	};

	class UIOutputer : public Outputer
	{
	private:
		UIOutputer operator=(const UIOutputer& obj) = delete;
		UIOutputer(const UIOutputer& obj) = delete;

		void outputMessage(const Message& mssg) const override;
		void outputWarning(const Warning& wrn) const override;
		void outputError(const Error& err) const override;
	};
}