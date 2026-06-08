#ifndef PROGRA_III_P4_H
#define PROGRA_III_P4_H
#include <mutex>
#include <iterator>
#include <cstddef>

template <typename T>
class linked_list_t {
    struct node_t {
        T value;
        node_t* next;
        node_t(const T& v, node_t* n = nullptr) : value(v), next(n) {}
    };

    node_t* head = nullptr;
    int count = 0;
    std::mutex mtx;

public:
    linked_list_t() = default;

    ~linked_list_t() {
        while (head) { node_t* tmp = head; head = head->next; delete tmp; }
    }

    void push_front(const T& value) {
        std::lock_guard<std::mutex> lock(mtx);
        head = new node_t(value, head);
        ++count;
    }

    void pop_front() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!head) return;
        node_t* tmp = head;
        head = head->next;
        delete tmp;
        --count;
    }

    bool empty() {
        std::lock_guard<std::mutex> lock(mtx);
        return head == nullptr;
    }

    int size() {
        std::lock_guard<std::mutex> lock(mtx);
        return count;
    }

    class iterator {
        node_t* current;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        iterator(node_t* p = nullptr) : current(p) {}

        reference operator*()  const { return current->value; }
        pointer   operator->() const { return &current->value; }

        iterator& operator++()    { current = current->next; return *this; }
        iterator  operator++(int) { iterator t = *this; current = current->next; return t; }

        bool operator==(const iterator& o) const { return current == o.current; }
        bool operator!=(const iterator& o) const { return current != o.current; }
    };


    iterator begin() { return iterator(head); }
    iterator end()   { return iterator(nullptr); }
};
#endif //PROGRA_III_P4_H