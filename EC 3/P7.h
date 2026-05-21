#ifndef PROGRA_III_P7_H
#define PROGRA_III_P7_H


namespace utec{
    template<typename dir, typename Valor>
    dir remover(dir dir1, dir dir2, Valor valor) {
        dir cont = dir1;
        while (dir1 != dir2) {
            if (*dir1 != valor) {
                *cont = *dir1;
                ++cont;
            }
            ++dir1;
        }
        return cont;
    }
};


#endif //PROGRA_III_P7_H