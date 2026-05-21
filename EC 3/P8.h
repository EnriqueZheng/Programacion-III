#ifndef PROGRA_III_P8_H
#define PROGRA_III_P8_H


namespace utec{
    template<typename Contenedor, typename Valor>
    void reemplazar(Contenedor dir1, Contenedor dir2, Valor valor,Valor reemplazo) {
        while (dir1 != dir2) {
            if (*dir1 == valor) {
                *dir1 = reemplazo;
            }
            ++dir1;
        }
    }
};


#endif //PROGRA_III_P8_H