#include <iostream>
#include <vector>
#include "P11.h"
using namespace std;


int main() {
    std::vector vec1 = {1, 2, 3};
    std::vector vec2 = {4, 5, 6};
    std::vector vec3 = {7, 8, 9};
    auto vec = utec::concat(vec1, vec2, vec3);
    for(const auto& item: vec)
        std::cout << item << " ";
    return 0;
}
