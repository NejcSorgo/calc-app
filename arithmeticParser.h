#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

class arithmeticParser
{
public:
	arithmeticParser();
	int izracunajRezultat(const std::string& izraz);
private:
	bool jeOperator(char znak);
	int prioritet(char operacija);
	double kvadratRezultata(double rezultat);
	double korenRezultata(double rezultat);
};

