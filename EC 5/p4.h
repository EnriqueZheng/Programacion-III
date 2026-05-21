#ifndef PROGRA_III_P4_H
#define PROGRA_III_P4_H
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


template<typename Container,template <typename...> class ResultContainer = vector>
ResultContainer<typename Container::value_type> delete_duplicated(Container& container) {
    using T = typename Container::value_type;
    ResultContainer<T> nums;

    for (const auto& item : container) {
        if (find(nums.begin(), nums.end(), item) == nums.end()) {
            nums.push_back(item);
        }
    }
    return nums;
}

#endif //PROGRA_III_P4_H