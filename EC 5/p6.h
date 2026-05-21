#ifndef PROGRA_III_P6_H
#define PROGRA_III_P6_H
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;
template<template <typename...> class Container,typename T,typename... Rest>
Container<vector<T>> zip(const Container<T>& first, const Rest&... rest) {
    Container<vector<T>> resultado;
    auto min_size = min({
        distance(begin(first), end(first)),
        distance(begin(rest),  end(rest))...
    });
    auto iters = make_tuple(begin(first), begin(rest)...);
    for (decltype(min_size) i = 0; i < min_size; ++i) {
        vector<T> fila;
        fila.reserve(1 + sizeof...(Rest));

        apply([&fila](auto&... its) {
            (fila.push_back(*its), ...);  
            (++its, ...);                  
        }, iters);

        resultado.push_back(move(fila));
    }

    return resultado;
}

#endif //PROGRA_III_P6_H