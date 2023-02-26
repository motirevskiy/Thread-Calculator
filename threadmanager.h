#ifndef THREADMANAGER_H
#define THREADMANAGER_H
#include "threadcalc.h"
#include <thread>

class threadManager
{
public:
	threadManager(int countCommands, std::string * commands, double *answers);
	void distribution();
private:
	int countCommand;
	std::string *commands;
	int countForThreads;
	threadCalc threads[4];
	double *answers;
};

#endif // THREADMANAGER_H
