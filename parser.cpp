
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include "logic_gates.h"
std::vector<bool> stringToBoolean(std::string input) {
    std::vector<bool> return_array;
    //std::cout<<"Converted: ";
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '1')
            return_array.push_back(true);
        else
            return_array.push_back(false);
        //std::cout << return_array.back();
    }
    //std::cout<<std::endl;
    return return_array;
}
std::string booleanToString(std::vector<bool> input) {
    std::string return_string;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i])
            return_string.push_back('1');
        else
            return_string.push_back('0');
        //std::cout << return_string.back();
    }
    //  //std::cout<<"BooleantoString: "<<return_string<<std::endl;
    return return_string;
}

void testVector(std::vector<bool> val)
{
    for (auto&& i : val) {
        std::cout << i;
    }
    std::cout << std::endl;
}
std::string parseNOTgates(std::string input, int size)
{
    std::string result;
    std::string stnum;
    for (int i = 0; i < input.size(); ++i) {
        int loc = input.find("NOT", i);
        if (loc > -1)
        {
            //std::cout<<"Found not! "<<loc<<std::endl;
            int next_whitespace = input.find(' ', loc + 1);
            stnum = input.substr(next_whitespace + 1, input.find_first_of(" )(", next_whitespace + 1) - next_whitespace - 1);
            //std::cout<<stnum<<std::endl;
            std::vector<bool> num = stringToBoolean(stnum);
            std::string notstring = booleanToString(notgate(num, size));
            input.erase(loc, input.find_first_of(" )(", next_whitespace + 1) - loc);
            input.insert(loc, notstring);
            i = next_whitespace;
        }
        else
        {
            break;
        }

    }
    result = input;
    //std::cout<<" Parsed not gates: "<<input<<std::endl;
    return result;
}

int findClosingBracket(std::string text, int openPos) {
    int closePos = openPos;
    int counter = 1;
    while (counter > 0) {
        char c = text[++closePos];
        if (c == '(') {
            counter++;
        }
        else if (c == ')') {
            counter--;
        }
    }
    return closePos;
}
bool isOperation(std::string input)
{

    if (input == "NOR" || input == "OR" || input == "AND" || input == "XNOR" || input == "NAND" || input == "XOR")
    {
        return true;
    }
    return false;
}
std::vector<bool> parseOperation(std::vector<bool> val, std::string input, int size) {
    std::vector<bool>  num, result;
    std::string operation;
    int first_occurence = input.find(' ');
    //std::cout<<std::endl<<first_occurence<<std::endl;
    operation = input.substr(0, first_occurence);
    //std::cout<<"First occurence:"<<first_occurence<<std::endl;
    //std::cout <<"Operation: "<<operation<<std::endl;
    //std::cout<<"Number:"<<input.substr(first_occurence + 1)<<std::endl;
    //std::cout<<"Value:";
    //TestVector(val);
    //std::cout<<std::endl;
    num = stringToBoolean(input.substr(first_occurence + 1));
    if (operation == "AND" || operation == "and")
    {
        return andgate(val, num, size);
    }
    else if (operation == "OR" || operation == "or")
    {
        return orgate(val, num, size);
    }
    else if (operation == "XOR" || operation == "xor")
    {
        return xorgate(val, num, size);
    }
    else if (operation == "NOR" || operation == "nor")
    {
        return norgate(val, num, size);
    }
    else if (operation == "NAND" || operation == "nand")
    {
        return nandgate(val, num, size);
    }
    else if (operation == "XNOR" || operation == "xnor")
    {
        return xnorgate(val, num, size);
    }


    return result;
}
std::vector<bool> parseOperation(std::vector<bool> num1, std::vector<bool> num2, std::string operation, int size) {
    std::vector<bool>  result = num1;
    //std::cout<<"Operation:"<<operation<<std::endl;
    //std::cout<<" Num 1:";
    //TestVector(num1);
    //std::cout<<std::endl<<" Num 2:";
    //TestVector(num2);
    //std::cout<<std::endl;
    if (operation == "AND" || operation == "and")
    {
        return andgate(num1, num2, size);
    }
    else if (operation == "OR" || operation == "or")
    {
        return orgate(num1, num2, size);
    }
    else if (operation == "XOR" || operation == "xor")
    {
        return xorgate(num1, num2, size);
    }
    else if (operation == "NOR" || operation == "nor")
    {
        return norgate(num1, num2, size);
    }
    else if (operation == "NAND" || operation == "nand")
    {
        return nandgate(num1, num2, size);
    }
    else if (operation == "XNOR" || operation == "xnor")
    {
        return xnorgate(num1, num2, size);
    }
    return result;
}
std::vector<bool> parseLogicGates(std::string input, int size) {
    std::vector<bool> result;
    //std::cout<<std::endl<<"Parse Input : "<<input<<std::endl;
    result.reserve(size);
    bool result_set = false;
    for (int i = 0; i < input.size(); i++) // main loop za preverjanje
    {
        //std::cout<<i<<std::endl;
        if (!result_set && isdigit(input[i])) // nastavi zacetno cifro
        {
            result = stringToBoolean(input.substr(i, input.find(' ', i) - i));
            input.erase(i, input.find(' ', i) - i);
            i = 0;
            result_set = true;
            continue;
        }
        if (input[i] == '(') { // parsa pod oklepaje
            int closing_bracket = findClosingBracket(input, i);
            result = parseLogicGates(input.substr(i + 1, closing_bracket - i - 1), size); // parsa substring
            i = closing_bracket;
            //std::cout<<std::endl<<i<<std::endl;
            if (i < 0)
                break;
            continue;
        }
        if (isOperation(input.substr(i, input.find(' ', i + 1) - i)))
        {
            std::string operation = input.substr(i, input.find(' ', i + 1) - i);
            if (input[input.find(' ', i + 1) + 1] == '(')
            {
                //std::cout<<"Found bracket : "<<operation<<std::endl;
                int bruh = input.find(' ', i + 1) + 1;
                i = bruh;
                int closing_bracket = findClosingBracket(input, bruh);
                result = parseOperation(parseLogicGates(input.substr(i + 1, closing_bracket - i - 1), size), result, operation, size); // parsa substring
                i = closing_bracket;
                //std::cout<<std::endl<<i<<std::endl;
                if (i < 0)
                    break;
                continue;
            }
            else
            {

                int first_occurence = input.find(' ', i + 1);
                std::string temp = input.substr(i, input.find(' ', first_occurence + 1) - i);
                //std::cout<<"Found no bracket : "<<operation<<" parseOperation Input: "<<temp<<" ParseOperation value:";
                //TestVector(result);
                result = parseOperation(result, temp, size);
                i = input.find(' ', first_occurence + 1) - 1;
            }

        }
        else
        {
            //std::cout<<"Not found :"<<input.substr(i,input.find(' ', i + 1)-i)<<std::endl;
        }


    }
    return result;
}
