#include "commandgenerator.h"
#include <iostream>

commandGenerator::commandGenerator(int commandCount, int freq)
{
	commandGenerator::commandCount = commandCount;
	commandGenerator::freq = freq;
	commandGenerator::lastSignCount = 3;
	srand(time(NULL));
}

int commandGenerator::getRandomValue(int min, int max)
{
	int value = min + rand() % (max - min + 1);
	return value;
}

std::string commandGenerator::getRandomSign()
{
	int value = commandGenerator::getRandomValue(1, 5);

	switch(value) {
	case 1:
		return "+";
	case 2:
		return "-";
	case 3:
		return "*";
	case 4:
		return "/";
	default:
		return "%";
	}
}

int commandGenerator::signCount()
{
	int min = 3;
	int max = 8;
	int signCount = 0;

	if (this->freq != 5) {
		min = this->lastSignCount - freq - 1;
		max = this->lastSignCount + freq + 1;
	}

	signCount = commandGenerator::getRandomValue(min, max);

	if (signCount > 8) {
		signCount = 8;
	}
	if (signCount < 3) {
		signCount = 3;
	}

	this->lastSignCount = signCount;

	return signCount;
}

std::string commandGenerator::generateCommand()
{
	int signCount = commandGenerator::signCount();

	int *valuesArray = new int[signCount + 1];
	std::string command = "";

	for (int i = 0; i < signCount; i++) {
		valuesArray[i] = getRandomValue(MIN_VALUE, MAX_VALUE);

		for (int z = 0; z < i; z++) {
			if ((valuesArray[i] < valuesArray[z] && valuesArray[i] - valuesArray[z] > -200) ||
				(valuesArray[i] > valuesArray[z] && valuesArray[i] - valuesArray[z] < 200)) {
				valuesArray[i] = getRandomValue(MIN_VALUE, MAX_VALUE);
				z = -1;
			}
		}

		command += std::to_string(valuesArray[i]) + " ";
		command += commandGenerator::getRandomSign() + " ";
	}

	command += std::to_string(getRandomValue(MIN_VALUE, MAX_VALUE));

	delete[] valuesArray;

	return command;
}
