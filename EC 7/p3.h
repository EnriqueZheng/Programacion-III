#ifndef PROGRA_III_P3_H
#define PROGRA_III_P3_H
#include <vector>
#include <thread>
#include <algorithm>

template <typename T>
bool is_prime(T n) {
    if (n < 2) return false;
    for (T i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

template <typename T, template<typename ...> class Container>
void get_primes(Container<T>& cnt, T start, T stop) {
    if (start >= stop) return;

    unsigned nthreads = std::thread::hardware_concurrency();
    if (nthreads == 0) nthreads = 2;

    T total = stop - start;
    T chunk = (total + (T)nthreads - 1) / (T)nthreads;

    std::vector<Container<T>> partials(nthreads);
    std::vector<std::thread> workers;

    for (unsigned i = 0; i < nthreads; ++i) {
        T s = start + (T)i * chunk;
        if (s >= stop) break;
        T e = std::min(stop, s + chunk);
        workers.emplace_back([s, e, i, &partials]() {
            for (T n = s; n < e; ++n)
                if (is_prime(n))
                    partials[i].push_back(n);
        });
    }

    for (auto& w : workers) w.join();

    for (auto& part : partials)
        for (auto& p : part)
            cnt.push_back(p);
}
#endif //PROGRA_III_P3_H