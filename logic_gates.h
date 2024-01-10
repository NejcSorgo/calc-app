#pragma once
#include <vector>
#include <iostream>

std::vector<bool> andgate(std::vector<bool> input1, std::vector<bool> input2, int n);
std::vector<bool> orgate(std::vector<bool> input1, std::vector<bool> input2, int n);
std::vector<bool> xorgate(std::vector<bool> input1, std::vector<bool> input2, int n);
std::vector<bool> nandgate(std::vector<bool> input1, std::vector<bool> input2, int n);
std::vector<bool> norgate(std::vector<bool> input1, std::vector<bool> input2, int n);
std::vector<bool> xnorgate(std::vector<bool> input1, std::vector<bool> input2, int n);