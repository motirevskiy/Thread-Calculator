#include "singlecalc.h"

singleCalc::singleCalc()
{

}

std::string *singleCalc::split(std::string command)
{
	std::string delimiter = " ";
	std::string *splited;

	int size = 0;
	for (auto ch: command) {
		if (ch == ' ')
			size++;
	}

	splited = new std::string[size + 2];

	size_t pos = 0;
	int i = 0;

	while((pos = command.find(delimiter)) != std::string::npos) {
		std::string token = command.substr(0, pos);
		splited[i] = token;
		command.erase(0, pos + delimiter.length());
		i++;
	}

	splited[i] = command;
	splited[i + 1] = "\0";
	return splited;
}

double singleCalc::calculation(std::string command)
{
	std::string *commands = singleCalc::split(command);

	for (int i = 0; !commands[i].empty(); i++) {
		if (commands[i] == "*" || commands[i] == "/" || commands[i] == "%") {
			double x = singleCalc::oneAction(commands[i], commands[i - 1], commands[i + 1]);
			commands[i] = std::to_string(x);
			commands[i - 1] = "x";
			commands[i + 1] = "x";
			commands = singleCalc::split(singleCalc::copyArray(commands));
			i -= 1;
		}
	}

	for (int i = 0; !commands[i].empty(); i++) {
		if (commands[i] == "-" || commands[i] == "+") {
			double x = singleCalc::oneAction(commands[i], commands[i - 1], commands[i + 1]);
			commands[i] = std::to_string(x);
			commands[i - 1] = "x";
			commands[i + 1] = "x";
			commands = singleCalc::split(singleCalc::copyArray(commands));
			i -= 1;
		}
	}
	double answer = std::stod(commands[0]);
	delete[] commands;
	return answer;
}

double singleCalc::oneAction(std::string action, std::string a, std::string b)
{
		if (action == "*")
			return (double)std::stod(a) * (double)std::stod(b);
		else if (action == "/") {
			if ((double)std::stod(b) == 0) {
				std::cout << "Diving by zero\n";
				return 0;
			}
			return (double)std::stod(a) / (double)std::stod(b);
		}
		else if (action == "%") {
			if ((int)std::stod(b) == 0) {
				std::cout << "Diving by zero\n";
				return 0;
			}
			return (int)std::stod(a) % (int)std::stod(b);
		}
		else if (action == "+")
			return std::stod(a) + std::stod(b);
		else
			return std::stod(a) - std::stod(b);
}

std::string singleCalc::copyArray(std::string *command)
{
	std::string newString = "";
	int counter = 0;

	while (!command[counter].empty()) {
		if (command[counter] != "x") {
			newString += command[counter];
			newString += " ";
		}
		counter++;
	}

	delete[] command;
	return newString;
}
