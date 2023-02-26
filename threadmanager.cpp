#include "threadmanager.h"

threadManager::threadManager(int countCommands, std::string *commands, double *answers)
{
	this->commands = commands;
	this->countCommand = countCommands;
	this->countForThreads = this->countCommand / 4;
	this->answers = answers;
}

void threadManager::distribution()
{


	for (int i = 0; i < 4; i++) {
		if (i < 3)
			this->threads[i] = threadCalc(this->countForThreads,
										  this->countForThreads * i,
										  threadManager::answers);
		else
			this->threads[i] = threadCalc(this->countCommand - (this->countForThreads * 3),
										  this->countForThreads * i,
										  threadManager::answers);
	}

	int a = this->countForThreads;
	int iterator = 0;

	for (int i = 0; i < this->countCommand; i++) {
		if (i >= a && iterator != 3) {
			iterator++;
			a += this->countForThreads;
		}
		this->threads[iterator].addCommand(threadManager::commands[i]);
	}

	for (int i = 0; i < 4; i++) {
		this->threads[i].start();
		threadManager::threads[i].threadJoin();
	}

}
