#ifndef THREADCALC_H
#define THREADCALC_H

#include "singlecalc.h"
#include <iostream>
#include <thread>
#include <chrono>


class threadCalc
{
public:
	threadCalc(){};
	threadCalc(int size, int startIndex, double *forAnswers);
	void	addCommand(std::string command);
	void	start();
	void	threadJoin();
	double	*final;
	float	progress;
private:
	std::thread thread;
	std::string *commands;
	int			size;
	int			iterator;
	void		calculating();
	double		*answers;
	int			startIndex;
};

#endif // THREADCALC_H
