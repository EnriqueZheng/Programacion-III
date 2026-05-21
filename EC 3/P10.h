#ifndef PROGRA_III_P10_H
#define PROGRA_III_P10_H


namespace utec{
    template<typename T>
    T sum(T v1, T p2) {
        return v1 + p2;
    }
    template<typename... Args, typename T>
    T sum(T v1, Args... args) {
        return v1 + sum(args...);
    }

};


#endif //PROGRA_III_P10_H