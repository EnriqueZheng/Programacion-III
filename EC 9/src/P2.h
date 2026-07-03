#ifndef POO2_UNIT6_ADAPTADORES_POO_V2021_2_P2_H
#define POO2_UNIT6_ADAPTADORES_POO_V2021_2_P2_H
#include "stack_utec.h"

template <typename T>
utec::stack<T> join_stacks(utec::stack<T> a, utec::stack<T> b) {
    utec::stack<T> tmp;
    while (!b.empty()) { tmp.push(b.top()); b.pop(); }
    while (!tmp.empty()) { a.push(tmp.top()); tmp.pop(); }
    return a;
}

#endif //POO2_UNIT6_ADAPTADORES_POO_V2021_2_P2_H
