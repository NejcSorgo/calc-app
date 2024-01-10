//parses logic gates and arithmetic
//Dvojiški: 1 Desetiški : 2 Osmiški : 3 Šestnajstiški: 4
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
