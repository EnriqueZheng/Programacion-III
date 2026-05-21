#ifndef PROGRA_III_P5_H
#define PROGRA_III_P5_H

namespace utec {
    template<typename T,typename Objetivo>
    T buscar(T n1, T n2, Objetivo n3) {
        while (n1 != n2) {
            if (*n1 == n3) {
                return n1;
            }
            ++n1;
        }
        return n2;
    }
}


#endif //PROGRA_III_P5_H