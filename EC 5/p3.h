#ifndef PROGRA_III_P3_H
#define PROGRA_III_P3_H

#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template<typename Container,template <typename...> class ResultContainer = vector>
ResultContainer<typename Container::value_type> delete_range(Container& container, const size_t& val) {
    for (auto it = begin(container); it != end(container); it++) {
        if (*it == val) {container.erase(it);}
    }
    return container;
}

template<typename Container,template <typename...> class ResultContainer = vector>
ResultContainer<typename Container::value_type> delete_range(const Container& container,initializer_list<typename Container::value_type> values) {
    using T = typename Container::value_type;
    ResultContainer<T> resultado;

    for (const auto& item : container) {
        if (find(values.begin(), values.end(), item) == values.end()) {
            resultado.push_back(item);
        }
    }
    return resultado;
}

template<typename Container, template <typename...> class ResultContainer = vector>
ResultContainer<typename Container::value_type>
delete_range(const Container& container, const typename Container::value_type& val) {
    return delete_range<Container, ResultContainer>(container, {val});
}
#endif //PROGRA_III_P3_H