#ifndef PROGRA_III_P2_H
#define PROGRA_III_P2_H
#include <thread>


template<typename T, template<typename ...> class Container>
void increase_values(Container<T>& cnt, T value) {
    const size_t n = cnt.size();
    if (n == 0) return;
    unsigned int nthreads = std::thread::hardware_concurrency();
    if (nthreads == 0) nthreads = 2;
    if (nthreads > n) nthreads = static_cast<unsigned int>(n);
    std::vector<std::thread> hilos;
    hilos.reserve(nthreads);

    const size_t bloque = n / nthreads;
    auto it = cnt.begin();

    for (unsigned int i = 0; i < nthreads; ++i) {
        auto ini = it;
        size_t cant = (i == nthreads - 1) ? (n - bloque * i) : bloque;
        auto fin = std::next(ini, cant);
        it = fin;

        hilos.emplace_back([ini, fin, value]() {
            for (auto cur = ini; cur != fin; ++cur) {
                *cur += value;
            }
        });
    }
    for (auto& h : hilos) h.join();
}
#endif //PROGRA_III_P2_H