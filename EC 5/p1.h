#ifndef PROGRA_III_P1_H
#define PROGRA_III_P1_H
#include <vector>
#include <iterator>
#include <cstddef>
using namespace std;

template<typename Container,template <typename...> class ResultContainer = vector>
ResultContainer<Container> split_range(const Container& contenedor,size_t n) {
    ResultContainer<Container> resultado;
    if (n == 0) return resultado;

    auto total = distance(begin(contenedor), end(contenedor));
    auto tam   = total / static_cast<decltype(total)>(n);
    auto resto = total % static_cast<decltype(total)>(n);

    auto it = begin(contenedor);
    for (size_t i = 0; i < n; ++i) {
        auto chunk_size = tam + (i + 1 == n ? resto : 0);
        auto next_it = next(it, chunk_size);
        resultado.push_back(Container(it, next_it));
        it = next_it;
    }
    return resultado;
}

#endif //PROGRA_III_P1_H