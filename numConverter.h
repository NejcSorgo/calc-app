#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <bitset>
class numConverter
{
public:
	std::string DecimalToBinary(std::string input);
	std::string OctalToBinary(std::string input);
	std::string HexToBinary(std::string input);
	std::string BinaryToDecimal(std::string input);
	std::string BinaryToOctal(std::string input);
	std::string BinaryToHexadecimal(std::string input);
	std::string OctalToHexadecimal(std::string input);
	std::string OctalToDecimal(std::string input);
	std::string DecimalToOctal(std::string input);
	std::string DecimalToHex(std::string input);
	std::string HexToDecimal(std::string input);
	std::string HexToOctal(std::string input);
};

