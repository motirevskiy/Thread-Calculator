/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:08:25 by cgretche          #+#    #+#             */
/*   Updated: 2023/02/26 10:25:30 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                           COMPILATION                                      */
/*  Use:                 clang++ -std=c++17 *.cpp                             */
/*  Leaks check Use:    leaks --atExit -- ./a.out                             */
/* ************************************************************************** */


#include <iostream>
#include "coolmap.h"
#include "commandgenerator.h"
#include "threadmanager.h"

int main(int argc, char *argv[])
{
	int countOfCommand = 0;
	int freq = 0;

	std::cout << "Enter the count of commands - ";
	std::cin >> countOfCommand;
	std::cout << std::endl;
	std::cout << "Enter the frequency - ";
	std::cin >> freq;
	std::cout << std::endl;

	if (countOfCommand < 4 || freq < 0 || freq > 5) {
		std::cout << "error input data\n";
		return 1;
	}

	coolMap commandsMap = coolMap(countOfCommand);
	commandGenerator generator = commandGenerator(countOfCommand, freq);
	
	commandsMap.generateCommandMap(generator);
	threadManager manager = threadManager(countOfCommand, commandsMap.keyArray, commandsMap.valueArray);
	manager.distribution();

	for (int i = 0; i < countOfCommand; i++) {
		std::cout << i << "  " << commandsMap.keyArray[i] << " = " << commandsMap.valueArray[i] << std::endl;
	}

	delete[] commandsMap.keyArray;
	delete[] commandsMap.valueArray;

	return 0;
}
