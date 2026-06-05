#include <iostream>
#include <vector>
#include <deque>
#include "EC 7/p1.h"
using namespace std;
int main() {
    size_t n = 0;
    cin >> n;
    vector<long long> v1(n);
    for (auto &item: v1)
        cin >> item;
    auto total = sumar(v1);
    cout << total << endl;
    return 0;
}

