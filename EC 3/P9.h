#ifndef PROGRA_III_P9_H
#define PROGRA_III_P9_H


namespace utec {
    template<typename Contenedor, typename Valor>
    int contar(Contenedor dir1, Contenedor dir2, Valor valor) {
        int contador = 0;
        while (dir1 != dir2) {
            if (*dir1 == valor) {
                contador += 1;
            }
            ++dir1;
        }
        return contador;
    }
}


#endif //PROGRA_III_P9_H