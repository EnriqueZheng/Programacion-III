#ifndef PROGRA_III_P12_H
#define PROGRA_III_P12_H


namespace utec{
    template<typename T>
    T max(T n1, T n2) {
        if (n1 > n2) {
            return  n1;
        }
        return n2;
    }
    template<typename... Args, typename T>
    T max(T n1, Args... args) {
        return max(n1, max(args...));
    }
};


#endif //PROGRA_III_P12_H