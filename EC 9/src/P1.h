#ifndef POO2_UNIT6_ADAPTADORES_POO_V2021_2_P1_H
#define POO2_UNIT6_ADAPTADORES_POO_V2021_2_P1_H
#include "stack_utec.h"

template <typename T>
utec::stack<T> merge_stacks(utec::stack<T> a, utec::stack<T> b) {
    utec::stack<T> aux;
    while (!a.empty() && !b.empty()) {
        aux.push(b.top()); b.pop();
        aux.push(a.top()); a.pop();
    }
    while (!a.empty()) { aux.push(a.top()); a.pop(); }
    while (!b.empty()) { aux.push(b.top()); b.pop(); }
    utec::stack<T> result;
    while (!aux.empty()) { result.push(aux.top()); aux.pop(); }
    return result;
}

#endif //POO2_UNIT6_ADAPTADORES_POO_V2021_2_P1_H
