#include "../../src/include/Loger.h"
#include <iostream>

using namespace dl;

int main()
{
	Loger loger;
	ConsoleOutputer outputer;

	//Arg 1: message log, Arg 2: type log, Arg 3: create exception
	loger.addLog("Test log.", TypeLog::EMPTY_LOG, false);//Add log
	loger.process(outputer);//Process log in loger and output result

	loger.process("Test log.", TypeLog::EMPTY_LOG, false);//Process log
	loger.process("Test log.", TypeLog::EMPTY_LOG, false, outputer);//Process log and output result

	return 0;
}