//parses logic gates and arithmetic
//Dvoji�ki: 1 Deseti�ki : 2 Osmi�ki : 3 �estnajsti�ki: 4
#include "parser.h"
#include <string.h>
#include <string>
#include <vector>
std::vector<bool> parseLogicGates(std::string input, int size)
{
    std::vector<bool> result;
    result.reserve(size);
    for (int i = 0; i < input.size(); i++) // main loop za preverjanje 
    {
        //std::string operation;
       
        //if (input[i] == '(')
        //{
        //    parseLogicGates(input.substr(i+1,input.find(")", i + 1)- i - 1), size); // parsa substring
        //    i = input.find(")",i);
        //}
        //if (input[i] == ' ')
        //{
        //    if (isdigit(input[i + 1]))
        //    {
        //       std::string operation = input.substr(i + 1, input.find(' ', i + 1)); // naredi podniz med dvema naslednima presledkoma 
        //    }
        //}
        
    }
    return result;
}
