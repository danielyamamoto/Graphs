#pragma once

#ifndef DATA
#define DATA

#include <iostream>
#include <string>

using namespace std;

class Data {
public:
    Data(int, int, string);
    ~Data();

    int getNode();
    string getIP();

    friend ostream& operator<<(ostream& os, const Data& d); // Operador para imprimir data
    friend bool operator<(const Data& d1, const Data& d2); // Operador para comparar los accesos
    
private:
    int node, access;
    string ip;
};

#endif // DATA