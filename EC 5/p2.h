#ifndef PROGRA_III_P2_H
#define PROGRA_III_P2_H
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template<typename Container,template <typename...> class ResultContainer = vector>
ResultContainer<typename Container::value_type> sum_range(const Container& c1, const Container& c2) {
    
    using T = typename Container::value_type;
    ResultContainer<T> resultado;

    if (c1.empty() || c2.empty()) return resultado;

    auto size1 = distance(begin(c1), end(c1));
    auto size2 = distance(begin(c2), end(c2));
    auto total = max(size1, size2);

    auto it1 = begin(c1);
    auto it2 = begin(c2);

    for (decltype(total) i = 0; i < total; ++i) {
        resultado.push_back(*it1 + *it2);

        if (++it1 == end(c1)) it1 = begin(c1);
        if (++it2 == end(c2)) it2 = begin(c2);
    }

    return resultado;
}


#endif //PROGRA_III_P2_H