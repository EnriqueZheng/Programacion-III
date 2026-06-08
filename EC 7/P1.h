#ifndef PROGRA_III_P1_H
#define PROGRA_III_P1_H
#include <thread>
#include <numeric>
#include <iterator>
template <typename T, template <typename...> class Container>
T sumar(Container<T>& cnt) {
    const size_t n = cnt.size();
    if (n == 0) return T{};

    unsigned int nthreads = std::thread::hardware_concurrency();
    if (nthreads == 0) nthreads = 2;
    if (nthreads > n) nthreads = static_cast<unsigned int>(n);

    std::vector<T> parciales(nthreads, T{});
    std::vector<std::thread> hilos;
    hilos.reserve(nthreads);

    const size_t bloque = n / nthreads;
    auto it = cnt.begin();

    for (unsigned int i = 0; i < nthreads; ++i) {
        auto ini = it;
        size_t cant = (i == nthreads - 1) ? (n - bloque * i) : bloque;
        auto fin = std::next(ini, cant);
        it = fin;

        hilos.emplace_back([ini, fin, &parciales, i]() {
            parciales[i] = std::accumulate(ini, fin, T{});
        });
    }

    for (auto& h : hilos) h.join();

    return std::accumulate(parciales.begin(), parciales.end(), T{});
}
#endif //PROGRA_III_P1_H