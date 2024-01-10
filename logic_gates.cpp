#include <iostream>
#include <vector>
#include "logic_gates.h"
using namespace std;
vector<bool> andgate(vector<bool> input1, vector<bool> input2, int n) {
    cout << endl << endl << "AND Gate:" << endl;
    for (int i = 0; i < n -input1.size(); i++)
    {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni
         
    }
    for (int i = 0; i < n - input2.size(); i++)
    {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    cout << "Output: ";
    vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input1[i] == true && input2[i] == true) {
            rezultat[i] = true;
        }
        else {
            rezultat[i] = false;
        }
        //return rezultat;
        return rezultat;
    }
}

vector<bool> orgate(vector<bool> input1,vector<bool> input2, int n) {
    cout << endl << endl << "OR Gate:" << endl;
    cout << "Output: ";
    for (int i = 0; i < n - input1.size(); i++)
    {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - input2.size(); i++)
    {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    vector<bool> rezultat;
    rezultat.reserve(n);    
    for (int i = 0; i < n; i++) {
        if (input1[i] == true || input2[i] == true) {
            rezultat[i] = true;
        }
        else {
            rezultat[i] = false;
        }
        return rezultat;
    }
}

vector<bool> xorgate(vector<bool> input1,vector<bool> input2, int n) {
    cout << endl << endl << "XOR Gate:" << endl;
    cout << "Output: ";
    for (int i = 0; i < n - input1.size(); i++)
    {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - input2.size(); i++)
    {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input1[i] != input2[i]) {
            rezultat[i] = true;
        }
        else {
            rezultat[i] = false;
        }
        return rezultat;
    }
}

vector<bool> nandgate(vector<bool> input1,vector<bool> input2, int n) {
    cout << endl << endl << "NAND Gate:" << endl;
    cout << "Output: ";
    for (int i = 0; i < n - input1.size(); i++)
    {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - input2.size(); i++)
    {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input1[i] == input2[i]) {
            rezultat[i] = false;
        }
        else {
            rezultat[i] = true;
        }
        return rezultat;
    }
}

vector<bool> norgate(vector<bool> input1,vector<bool> input2, int n) {
    cout << endl << endl << "NOR Gate:" << endl;
    cout << "Output: ";
    for (int i = 0; i < n - input1.size(); i++)
    {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - input2.size(); i++)
    {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input1[i] == false && input2[i] == false) {
            rezultat[i] = true;
        }
        else {
            rezultat[i] = false;
        }
        return rezultat;
    }
}

vector<bool> xnorgate(vector<bool> input1,vector<bool> input2, int n) {
    cout << endl << endl << "XNOR Gate:" << endl;
    cout << "Output: ";
    for (int i = 0; i < n - input1.size(); i++)
    {
        input1.insert(input1.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    for (int i = 0; i < n - input2.size(); i++)
    {
        input2.insert(input2.begin(), false); // doda false vrednost ce slucajno ni puni

    }
    vector<bool> rezultat;
    rezultat.reserve(n);
    for (int i = 0; i < n; i++) {
        if (input1[i] != input2[i]) {
            rezultat[i] = false;
        }
        else {
            rezultat[i] = true;
        }
        return rezultat;
    }
}
