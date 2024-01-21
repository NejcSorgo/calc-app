#include "logicParserGates.h"

std::vector<bool> logicParserGates::andgate(std::vector<bool> input1, std::vector<bool> input2, int n) {
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni
    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
        // //std::cout<<i;
    }
    std::vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input1[i] && input2[i]) {
            rezultat.insert(rezultat.begin() + i, true);
        }
        else {
            rezultat.insert(rezultat.begin() + i, false);;
        }
        //std:://std::cout << input1[i] && input2[i];
    }
    //std::cout << endl;
    return rezultat;
}

std::vector<bool> logicParserGates::orgate(std::vector<bool> input1, std::vector<bool> input2, int n) {
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
        // //std::cout<<i;
    }

    std::vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input1[i] || input2[i]) {
            rezultat.insert(rezultat.begin() + i, true);
        }
        else {
            rezultat.insert(rezultat.begin() + i, false);
        }
        //std::cout << rezultat[i];
    }
    return rezultat;
}

std::vector<bool> logicParserGates::xorgate(std::vector<bool> input1, std::vector<bool> input2, int n) {
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni
    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
    }
    std::vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input1[i] != input2[i]) {
            rezultat.insert(rezultat.begin() + i, true);
        }
        else {
            rezultat.insert(rezultat.begin() + i, false);
        }

    }
    return rezultat;
}

std::vector<bool> logicParserGates::nandgate(std::vector<bool> input1, std::vector<bool> input2, int n) {
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); 

    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false);
    }
    std::vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (!input1[i] || !input2[i]) {
            rezultat.insert(rezultat.begin() + i, true);
        }
        else {
            rezultat.insert(rezultat.begin() + i, false);
        }
    }
    return rezultat;
}

std::vector<bool> logicParserGates::norgate(std::vector<bool> input1, std::vector<bool> input2, int n) {
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
    }
    std::vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (!input1[i] && !input2[i]) {
            rezultat.insert(rezultat.begin() + i, true);
        }
        else {
            rezultat.insert(rezultat.begin() + i, false);
        }
    }
    return rezultat;
}

std::vector<bool> logicParserGates::xnorgate(std::vector<bool> input1, std::vector<bool> input2, int n) {
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
    }
    std::vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input1[i] != input2[i]) {
            rezultat.insert(rezultat.begin() + i, false);
        }
        else {
            rezultat.insert(rezultat.begin() + i, true);
        }

    }
    return rezultat;
}

std::vector<bool> logicParserGates::notgate(std::vector<bool> input, int n) {
    int velikost_st_1 = input.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input.insert(input.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    std::vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input[i]) {
            rezultat.insert(rezultat.begin() + i, false);
        }
        else {
            rezultat.insert(rezultat.begin() + i, true);
        }

    }
    return rezultat;
}