#include <iostream>
#include <vector>
#include "logic_gateS.h"

using namespace std;

vector<bool> andgate(vector<bool> input1, vector<bool> input2, int n) {
    //std::cout << endl << endl << "AND Gate:" << endl;
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni
    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
        // //std::cout<<i;
    }
    //std::cout << endl << "Output: " << "Velikost: " << input2.size() << endl;
    vector<bool> rezultat;
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

vector<bool> orgate(vector<bool> input1, vector<bool> input2, int n) {
    //std::cout << endl << endl << "OR Gate:" << endl;
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
        // //std::cout<<i;
    }

    //std::cout << endl << "Output: " << "Velikost: " << input2.size() << endl;
    vector<bool> rezultat;
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

vector<bool> xorgate(vector<bool> input1, vector<bool> input2, int n) {
    //std::cout << endl << endl << "XOR Gate:" << endl;
    //std::cout << "Output: ";
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
        // //std::cout<<i;
    }
    vector<bool> rezultat;
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

vector<bool> nandgate(vector<bool> input1, vector<bool> input2, int n) {
    //std::cout << endl << endl << "NAND Gate:" << endl;
    //std::cout << "Output: ";
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
        // //std::cout<<i;
    }
    vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (!input1[i] || !input2[i]) {
            rezultat.insert(rezultat.begin() + i, true);
        }
        else {
            rezultat.insert(rezultat.begin() + i, false);
        }
        // //std::cout<<"bruh";
        //std::cout << rezultat[i];
    }
    return rezultat;
}

vector<bool> norgate(vector<bool> input1, vector<bool> input2, int n) {
    //std::cout << endl << endl << "NOR Gate:" << endl;
    //std::cout << "Output: ";
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
        // //std::cout<<i;
    }
    vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (!input1[i] && !input2[i]) {
            rezultat.insert(rezultat.begin() + i, true);
        }
        else {
            rezultat.insert(rezultat.begin() + i, false);
        }
        //std::cout << rezultat[i];
    }
    return rezultat;
}

vector<bool> xnorgate(vector<bool> input1, vector<bool> input2, int n) {
    //std::cout << endl << endl << "XNOR Gate:" << endl;
    //std::cout << "Output: ";
    int velikost_st_1 = input1.size();
    int velikost_st_2 = input2.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - velikost_st_2; i++) {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni
        // //std::cout<<i;
    }
    vector<bool> rezultat;
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

vector<bool> notgate(vector<bool> input, int n) {
    //std::cout << endl << endl << "NOT Gate:" << endl;
    //std::cout << "Output: ";
    int velikost_st_1 = input.size();
    for (int i = 0; i < n - velikost_st_1; i++) {
        input.insert(input.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    vector<bool> rezultat;
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