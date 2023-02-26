#include "coolmap.h"
#include <iostream>

coolMap::coolMap(int size)
{
	coolMap::keyArray = new std::string[size];
	coolMap::valueArray = new double[size];
	coolMap::mapSize = size;
}

bool coolMap::addNew(std::string key)
{

   int index = coolMap::makeIndexByHashValue(key);

   if (!coolMap::keyArray[index].empty()) {
	   return false;
   }
   coolMap::keyArray[index] = key;
   return true;
}

int coolMap::makeIndexByHashValue(std::string key)
{
	int hashValue = 0;
	int index = 0;

	for (int i = 0; i < key.length(); i++) {
		hashValue = ((unsigned long) hashValue * X + key[i]) % P;
	}

	index = hashValue % this->mapSize;
	return index;
}

void coolMap::generateCommandMap(commandGenerator generator)
{
	int counter = 0;
	int i = 0;
	while (counter < this->mapSize) {
		std::string command = generator.generateCommand();
		if (this->addNew(command)) {
			counter++;
		}
	}
}

