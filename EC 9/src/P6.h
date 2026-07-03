#ifndef POO2_UNIT6_ADAPTADORES_POO_V2021_2_P6_H
#define POO2_UNIT6_ADAPTADORES_POO_V2021_2_P6_H
#include "stack_utec.h"
#include <functional>

template <typename T>
T find_in_stack(utec::stack<T> s, std::function<bool(T)> cmpr) {
    while (!s.empty()) {
        T value = s.top();
        s.pop();
        if (cmpr(value)) return value;
    }
    return T{};
}

#endif //POO2_UNIT6_ADAPTADORES_POO_V2021_2_P6_H
