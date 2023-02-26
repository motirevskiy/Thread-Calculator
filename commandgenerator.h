#ifndef COMMANDGENERATOR_H
#define COMMANDGENERATOR_H

#include <string>
#include <stdlib.h>
#include <time.h>

#define MIN_VALUE -31032
#define MAX_VALUE  31032


class commandGenerator
{
public:
	commandGenerator(int commandCount, int freq);
	std::string generateCommand();

private:
	int getRandomValue(int min, int max);
	std::string getRandomSign();
	int signCount();
	int commandCount;
	int freq;
	int lastSignCount;
};

#endif // COMMANDGENERATOR_H
