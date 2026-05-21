#include <iostream>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "EC 5/p9.h"
using namespace std;


int main() {
    fixed_stack<int, 5> fs1 = {1, 2, 3, 4, 5};
    while (!fs1.empty()){
        std::cout << fs1.top() << " ";
        fs1.pop();
    }
    // 5 4 3 2 1
    return 0;
}

