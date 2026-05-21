#ifndef PROG3_UNIT2_TEMPLATE_FUNCTION_V2023_1_P1_H
#define PROG3_UNIT2_TEMPLATE_FUNCTION_V2023_1_P1_H
#include <iostream>
using namespace std;

namespace utec{
    template<typename T>
    static int count_char(const T &t, char caracter) {
        int count = 0;
        for (auto c : t) {
            if (tolower(c) == caracter) {
                count += 1;
            }
        }
        return count;
    }
};


#endif //PROG3_UNIT2_TEMPLATE_FUNCTION_V2023_1_P1_H
