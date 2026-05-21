#ifndef PROGRA_III_P11_H
#define PROGRA_III_P11_H
#include <string>
#include <vector>
using namespace std;
namespace utec {
    template<typename T>
    auto to_concat(T val) { return val; }

    inline string to_concat(const char* val) { return string(val); }

    template<typename T>
    vector<T> operator+(vector<T> a, const vector<T>& b) {
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }

    template<typename T>
    auto concat(T p1) {
        return to_concat(p1);
    }

    template<typename T, typename... Args>
    auto concat(T p1, Args... args) {
        return to_concat(p1) + concat(args...);
    }

}

#endif //PROGRA_III_P11_H