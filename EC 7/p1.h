#ifndef PROGRA_III_P1_H
#define PROGRA_III_P1_H
#include <thread>
#include <numeric>
#include <iterator>
template <typename T, template <typename...> class Container>
T sumar(Container<T>& cnt) {
    return std::accumulate(cnt.begin(), cnt.end(), T{});
}

#endif //PROGRA_III_P1_H