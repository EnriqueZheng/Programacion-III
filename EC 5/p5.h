#ifndef PROGRA_III_P5_H
#define PROGRA_III_P5_H
#include <tuple>

template <typename... Args>
std::tuple<Args&...> unpack(Args&... args) {
    return std::tuple<Args&...>(args...);
}


#endif //PROGRA_III_P5_H