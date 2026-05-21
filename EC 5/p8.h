#ifndef PROGRA_III_P8_H
#define PROGRA_III_P8_H
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <regex>
using namespace std;

template <template <typename...> class ResultContainer = vector>
ResultContainer<string> filter_codes(const string& filename, char letter) {

    ifstream file(filename);
    if (!file) return ResultContainer<string>{};
    const regex pattern("[a-z]{4}[0-9]{3}");
    vector<string> temp;
    string code;
    while (file >> code) {
        if (regex_match(code, pattern) && code.front() == letter) {
            temp.push_back(code);
        }
    }
    sort(temp.begin(), temp.end());
    return ResultContainer<string>(temp.begin(), temp.end());
}

#endif //PROGRA_III_P8_H