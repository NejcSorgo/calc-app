#pragma once
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

#include "logicParserGates.h"

class logicParser
{
private:
	logicParserGates* logic_gates;
public:
	std::vector<bool> parseLogicGates(std::string input, int size);
	std::string booleanToString(std::vector<bool> input);
	std::string parseNOTgates(std::string input, int size);
	logicParser();
	~logicParser();
private:
	std::vector<bool> stringToBoolean(std::string input);
	void testVector(std::vector<bool> val);
	int findClosingBracket(std::string text, int openPos);
	bool isOperation(std::string input);
	std::vector<bool> parseOperation(std::vector<bool> val, std::string input, int size);
	std::vector<bool> parseOperation(std::vector<bool> num1, std::vector<bool> num2, std::string operation, int size);
};

