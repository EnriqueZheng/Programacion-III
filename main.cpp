#include <iostream>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "EC 5/p6.h"
using namespace std;


int main() {
    std::list<int> v1 = { 11, 12, 13 };
    std::list<int> v2 = { 21, 22, 23 };
    std::list<int> v3 = { 31, 32, 33 };
    auto result = zip(v1, v2, v3);
    // result sería del tipo: list<vector<int>>
    for (const auto& row : result) {
        for (const auto& value : row)
            std::cout << value << " ";
        std::cout << std::endl;
    }
    // lo impreso sería:
    //	11 21 31
    //	12 22 32
    //	13 23 33
    return 0;
}

