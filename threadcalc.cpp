#include "threadcalc.h"


threadCalc::threadCalc(int size, int startIndex, double *forAnswers)
{
	this->size = size;
	this->commands = new std::string[size];
	this->answers = new double[size];
	this->iterator = 0;
	this->final = forAnswers;
	this->startIndex = startIndex;
}

void threadCalc::addCommand(std::string command) {
	this->commands[this->iterator] = command;
	this->iterator++;
}

void threadCalc::calculating()
{
	singleCalc calculator;
	for (int i = 0; i < threadCalc::size; i++) {
		this->answers[i] = calculator.calculation(this->commands[i]);
		this->progress = (float)i / ((float)size - 1) * 100;
		// std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 10) + 1));
	}
	int a = 0;
	for (int i = this->startIndex; a < size; i++) {
		final[i] = this->answers[a];
		a++;
	}
	delete[] this->commands;
	delete[] this->answers;
}

void threadCalc::start()
{

	this->thread = std::thread([&]() {
		this->calculating();
	});
}

void threadCalc::threadJoin() {
	this->thread.join();
}

