#include <iostream>
#include <deque>
#include "EC 5/p1.h"
using namespace std;

template<template<typename, typename...> typename Container, typename T>
T sum(Container<T>& t) {
    T sum = 0;
    for (auto& x:t) {
        sum = sum + x;
        cout<<x<<endl;
    }
    return sum;
}

int main() {
    deque<int> d1 = {1, 2, 3, 4, 5, 6, 7};
    auto resultado = split_range(d1, 3};
        // resultado[0] = {1, 2};
            // resultado[1] = {3, 4};
                // resultado[2] = {5, 6, 7};
    return 0;
}

