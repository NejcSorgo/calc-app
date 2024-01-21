#include "numConverter.h"
//using namespace std;
std::string numConverter::DecimalToBinary(std::string input) {
    std::regex numberRegex("\\b\\d+\\b");
    std::stringstream ss(input);
    std::string token;
    std::string result;

    while (getline(ss, token, ' ')) {
        std::smatch match;
        if (regex_search(token, match, numberRegex)) {
            std::string extractedNumber = match.str();
            int number = stoi(extractedNumber);

            std::bitset<32> binaryNumber(number);
            std::string binaryString = binaryNumber.to_string();
            size_t found = binaryString.find('1');
            if (found != std::string::npos) {
                binaryString = binaryString.substr(found);
            } else {
                binaryString = "0";
            }

            token = regex_replace(token, std::regex(extractedNumber), binaryString);
        }
        result += token + " ";
    }
    result.pop_back();

    return result;
}
std::string numConverter::OctalToBinary(std::string input) {
    std::regex numberRegex("\\b[0-7]+\\b");
    std::stringstream ss(input);
    std::string token;
    std::string result;

    while (getline(ss, token, ' ')) {
        std::smatch match;
        if (regex_search(token, match, numberRegex)) {
            std::string extractedNumber = match.str();
            int number = stoi(extractedNumber, 0, 8);

            std::bitset<32> binaryNumber(number);
            std::string binaryString = binaryNumber.to_string();
            size_t found = binaryString.find('1');
            if (found != std::string::npos) {
                binaryString = binaryString.substr(found);
            } else {
                binaryString = "0";
            }

            token = regex_replace(token, std::regex(extractedNumber), binaryString);
        }
        result += token + " ";
    }

    result.pop_back();

    return result;
}
std::string numConverter::HexToBinary(std::string input) {
    std::regex numberRegex("\\b[0-9a-fA-F]+\\b");
    std::stringstream ss(input);
    std::string token;
    std::string result;

    while (getline(ss, token, ' ')) {
        std::smatch match;
        if (regex_search(token, match, numberRegex)) {
            std::string extractedNumber = match.str();
            int number = stoi(extractedNumber, 0, 16);

            std::bitset<32> binaryNumber(number);
            std::string binaryString = binaryNumber.to_string();
            size_t found = binaryString.find('1');
            if (found != std::string::npos) {
                binaryString = binaryString.substr(found);
            } else {
                binaryString = "0";
            }

            token = regex_replace(token, std::regex(extractedNumber), binaryString);
        }
        result += token + " ";
    }

    result.pop_back();

    return result;
}
std::string numConverter::BinaryToDecimal(std::string input) {
    std::regex binaryRegex("\\b[01]+\\b");
    std::string result;

    std::sregex_iterator it(input.begin(), input.end(), binaryRegex);
    std::sregex_iterator end;

    size_t lastPos = 0;

    while (it != end) {
        std::smatch match = *it;
        std::string binaryNumber = match.str();

        int decimalNumber = stoi(binaryNumber, 0, 2);

        result += input.substr(lastPos, match.position() - lastPos);

        result += std::to_string(decimalNumber);

        lastPos = match.position() + match.length();

        ++it;
    }

    result += input.substr(lastPos);

    return result;
}
std::string numConverter::BinaryToOctal(std::string input) {
    std::regex binaryRegex("\\b[01]+\\b");
    std::string result;

    std::sregex_iterator it(input.begin(), input.end(), binaryRegex);
    std::sregex_iterator end;

    size_t lastPos = 0;

    while (it != end) {
        std::smatch match = *it;
        std::string binaryNumber = match.str();

        while (binaryNumber.length() % 3 != 0) {
            binaryNumber = '0' + binaryNumber;
        }

        std::string octalString;
        for (size_t i = 0; i < binaryNumber.length(); i += 3) {
            std::string binarySet = binaryNumber.substr(i, 3);
            int decimalNumber = stoi(binarySet, 0, 2);
            octalString += std::to_string(decimalNumber);
        }

        result += input.substr(lastPos, match.position() - lastPos);

        result += octalString;

        lastPos = match.position() + match.length();

        ++it;
    }

    result += input.substr(lastPos);

    return result;
}
std::string numConverter::BinaryToHexadecimal(std::string input) {
    std::regex binaryRegex("\\b[01]+\\b");
    std::string result;

    std::sregex_iterator it(input.begin(), input.end(), binaryRegex);
    std::sregex_iterator end;

    size_t lastPos = 0;

    while (it != end) {
        std::smatch match = *it;
        std::string binaryNumber = match.str();

        while (binaryNumber.length() % 4 != 0) {
            binaryNumber = '0' + binaryNumber;
        }

        std::string hexString;
        for (size_t i = 0; i < binaryNumber.length(); i += 4) {
            std::string binarySet = binaryNumber.substr(i, 4);
            int decimalNumber = stoi(binarySet, 0, 2);
            hexString += "0123456789ABCDEF"[decimalNumber];
        }

        result += input.substr(lastPos, match.position() - lastPos);

        result += hexString;

        lastPos = match.position() + match.length();

        ++it;
    }

    result += input.substr(lastPos);

    return result;
}

std::string numConverter::OctalToHexadecimal(std::string input){
    std::string result = OctalToBinary(input);
    std::string resultMain = BinaryToHexadecimal(result);
    return resultMain;
}
std::string numConverter::OctalToDecimal(std::string input){
    std::string result = OctalToBinary(input);
    std::string resultMain = BinaryToDecimal(result);
    return resultMain;
}

std::string numConverter::DecimalToOctal(std::string input){
    std::string result = DecimalToBinary(input);
    std::string resultMain = BinaryToOctal(result);
    return resultMain;
}
std::string numConverter::DecimalToHex(std::string input){
    std::string result = DecimalToBinary(input);
    std::string resultMain = BinaryToHexadecimal(result);
    return resultMain;
}

std::string numConverter::HexToDecimal(std::string input){
    std::string result = HexToBinary(input);
    std::string resultMain = BinaryToDecimal(result);
    return resultMain;
}
std::string numConverter::HexToOctal(std::string input){
    std::string result = HexToBinary(input);
    std::string resultMain = BinaryToOctal(result);
    return resultMain;
}
