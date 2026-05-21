#ifndef PROGRA_III_P2_H
#define PROGRA_III_P2_H
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

namespace utec{
    template<typename T>
     static vector<string> split(const T& t,const char c) {
        vector<string> palabras;
        string palabra;
        stringstream ss(t);
        while (getline(ss,palabra,c)) {
            palabras.push_back(string(t));
        }
        return palabras;
    }

};

#endif //PROGRA_III_P2_H