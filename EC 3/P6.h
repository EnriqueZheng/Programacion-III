
#ifndef PROGRA_III_P6_H
#define PROGRA_III_P6_H
#include <vector>
#include <iostream>
using namespace std;

namespace utec {
    template <typename T, typename Copia>
    Copia copiar(T dir1, T dir2, Copia copia) {
        while (dir1 != dir2) {
            *copia = *dir1;
            ++copia;
            ++dir1;
        }
        return copia;
    }
};


#endif //PROGRA_III_P6_H