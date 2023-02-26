#ifndef COOLMAP_H
#define COOLMAP_H
#define P 2147483647
#define X 468736
#include <string>
#include "commandgenerator.h"


class coolMap
{
public:
	coolMap(int size);
	void generateCommandMap(commandGenerator generator);
	std::string *keyArray;
	double *valueArray;
private:
	bool addNew(std::string key);
	int makeIndexByHashValue(std::string key);
	int mapSize;
};

#endif // COOLMAP_H
