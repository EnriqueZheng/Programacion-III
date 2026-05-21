#include <iostream>
#include <deque>
#include <forward_list>
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
    std::string all = "El mundo es ancho y ajeno";
    auto chunks = split_range(all, 5);
    for (const auto& part : chunks) {
        std::cout << '|' << part;
    }   // |El mu|ndo e|s anc|ho y |ajeno
    return 0;
}

