#ifndef POO2_UNIT6_ADAPTADORES_POO_V2021_2_QUEUE_UTEC_H
#define POO2_UNIT6_ADAPTADORES_POO_V2021_2_QUEUE_UTEC_H

#include <deque>
#include <cstddef>
#include <utility>

namespace utec {
    template <typename Container>
    concept PopFrontConcept = requires(Container c) {
        c.pop_front();
    };

    template <typename T, PopFrontConcept Container = std::deque<T>>
    class queue {
        Container c;
    public:
        using value_type = T;
        using container_type = Container;
        using size_type = std::size_t;
        using reference = T&;
        using const_reference = const T&;

        queue() = default;
        void push(const T& value) { c.push_back(value); }
        void push(T&& value) { c.push_back(std::move(value)); }
        void pop() { c.pop_front(); }
        reference front() { return c.front(); }
        const_reference front() const { return c.front(); }
        reference back() { return c.back(); }
        const_reference back() const { return c.back(); }
        [[nodiscard]] bool empty() const { return c.empty(); }
        [[nodiscard]] size_type size() const { return c.size(); }
    };
}

#endif // POO2_UNIT6_ADAPTADORES_POO_V2021_2_QUEUE_UTEC_H
