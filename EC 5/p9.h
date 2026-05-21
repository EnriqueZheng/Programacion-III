#ifndef PROGRA_III_P9_H
#define PROGRA_III_P9_H

#include <array>
#include <initializer_list>
#include <iterator>
#include <cstddef>
#include <utility>

template <typename T, std::size_t sz>
class fixed_stack_pusher;

template <typename T, std::size_t sz>
class fixed_stack {
    std::array<T, sz> data{};
    std::size_t count = 0;

    friend class fixed_stack_pusher<T, sz>;

public:
    fixed_stack() = default;

    fixed_stack(std::initializer_list<T> lst) {
        for (const auto& v : lst) {
            if (count == sz) break;
            data[count++] = v;
        }
    }

    bool push(T value) {
        if (count == sz) return false;
        data[count++] = std::move(value);
        return true;
    }

    void pop() {
        if (count > 0) --count;
    }

    T& top()             { return data[count - 1]; }
    const T& top() const { return data[count - 1]; }

    bool empty() const { return count == 0; }
    int  size()  const { return static_cast<int>(count); }
};

template <typename T, std::size_t sz>
class fixed_stack_pusher {
    fixed_stack<T, sz>* stack;

public:
    using iterator_category = std::output_iterator_tag;
    using value_type        = void;
    using difference_type   = void;
    using pointer           = void;
    using reference         = void;

    explicit fixed_stack_pusher(fixed_stack<T, sz>& s) : stack(&s) {}

    fixed_stack_pusher& operator*()       { return *this; }
    fixed_stack_pusher& operator++()      { return *this; }
    fixed_stack_pusher  operator++(int)   { return *this; }

    fixed_stack_pusher& operator=(T value) {
        stack->push(std::move(value));
        return *this;
    }
};
#endif //PROGRA_III_P9_H