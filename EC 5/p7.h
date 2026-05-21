#ifndef PROGRA_III_P7_H
#define PROGRA_III_P7_H
#include <iterator>
using namespace std;

template<typename T>
T rotate_range(const T& Container, int n) {
    T contenedor;
    auto size = std::distance(Container.begin(), Container.end());
    if (size == 0) return contenedor;

    if (n > 0) {
        auto pos = std::next(Container.begin(), (size - (n % size)) % size);
        for (decltype(size) i = 0; i < size; ++i) {
            contenedor.push_back(*pos);
            ++pos;
            if (pos == Container.end()) pos = Container.begin();
        }
    }
    else {
        auto pos = std::next(Container.begin(), (-n) % size);
        for (decltype(size) i = 0; i < size; ++i) {
            contenedor.push_back(*pos);
            ++pos;
            if (pos == Container.end()) pos = Container.begin();
        }
    }
    return contenedor;
}

#endif //PROGRA_III_P7_H