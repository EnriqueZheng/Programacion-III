#include <iostream>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <sstream>
#include "EC 5/p3.h"
using namespace std;


int main() {
    std::vector<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5};
    auto v3 = delete_range(v1, 1); // {3, 4, 3, 2, 3, 4, 6, 5}
    for (auto i : v3) {
        cout << i << endl;
    }
    return 0;
}

