#ifndef POO2_UNIT6_ADAPTADORES_POO_V2021_2_P7_H
#define POO2_UNIT6_ADAPTADORES_POO_V2021_2_P7_H
#include "stack_utec.h"
#include <string>
#include <vector>
#include <cctype>

inline bool is_group_token(const std::string& s) {
    return !s.empty() && s.front() == '(';
}

inline bool is_operator_token(const std::string& s) {
    return s.size() == 1 && (s == "+" || s == "-" || s == "*" || s == "/");
}

inline std::string complete_equation(std::string source) {
    std::vector<std::string> items;
    std::string number;
    for (char ch : source) {
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            number += ch;
            continue;
        }
        if (!number.empty()) {
            items.push_back(number);
            number.clear();
        }
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            items.emplace_back(1, ch);
        } else if (ch == ')') {
            if (!items.empty() && is_group_token(items.back())) {
                std::string all;
                for (std::size_t i = 0; i < items.size(); ++i) {
                    if (i) all += " ";
                    all += items[i];
                }
                items.clear();
                items.push_back("(" + all + ")");
            } else if (!items.empty()) {
                std::string collected = items.back();
                items.pop_back();
                while (items.size() >= 2 &&
                       is_operator_token(items.back()) &&
                       !is_group_token(items[items.size() - 2]) &&
                       !is_operator_token(items[items.size() - 2])) {
                    std::string op = items.back();
                    items.pop_back();
                    std::string operand = items.back();
                    items.pop_back();
                    collected = operand + " " + op + " " + collected;
                }
                items.push_back("(" + collected + ")");
            }
        }
    }
    if (!number.empty()) items.push_back(number);

    std::string result;
    for (std::size_t i = 0; i < items.size(); ++i) {
        if (i) result += " ";
        result += items[i];
    }
    return result;
}

#endif //POO2_UNIT6_ADAPTADORES_POO_V2021_2_P7_H
