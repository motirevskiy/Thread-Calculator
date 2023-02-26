#ifndef SINGLECALC_H
#define SINGLECALC_H
#include <string>
#include <iostream>

class singleCalc
{
public:
	singleCalc();
	double calculation(std::string command);
private:
	double oneAction(std::string action, std::string a, std::string b);
	std::string copyArray(std::string *command);
	std::string *split(std::string command);
};

#endif // SINGLECALC_H
