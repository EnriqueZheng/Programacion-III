#ifndef PROGRA_III_P4_H
#define PROGRA_III_P4_H
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class point_t {
    int x = 0;
    int y = 0;
    int z = 0;
public:
    point_t() = default;
    point_t(int x, int y, int z) : x(x), y(y), z(z) {}
    [[nodiscard]] double distance() const {
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }
    bool operator<(const point_t& other) const {
        return distance() < other.distance();
    }
    bool operator>(const point_t& other) const {
        return distance() > other.distance();
    }
    friend ostream& operator<<(ostream& os, const point_t& p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")"
           << " [d=" << p.distance() << "]";
        return os;
    }
};

namespace sort {
    template<typename T, typename N>
        auto partition(T& contenedor,N low, N high) {
        auto pivot = contenedor[high];
        auto i = (low - 1);
        for (auto j = low; j < high; ++j) {
            if (contenedor[j] < pivot) {
                ++i;
                swap(contenedor[i],contenedor[j]);
            }
        }
        swap(contenedor[i+1], contenedor[high]);
        return i + 1;
    }

    template<typename T, typename N>
    void quick_sort(T& contenedor,N low, N high) {
        if (low < high) {
            auto pi = partition(contenedor,low,high);
            quick_sort(contenedor,low,pi-1);
            quick_sort(contenedor,pi+1,high);
        }
    }
}
namespace utec {
    template<typename T>
    [[nodiscard]]T quick_sort(T contenedor) {
        if (contenedor.size() > 1)
            sort::quick_sort(contenedor, 0, static_cast<int>(contenedor.size()) - 1);
        return contenedor;
    }
}


#endif //PROGRA_III_P4_H