#include "P5.h"
#include "stack_utec.h"

bool is_equation_balanced(std::string source) {
    utec::stack<char> s;
    for (char ch : source) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false;
            char open = s.top();
            s.pop();
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {
                return false;
            }
        }
    }
    return s.empty();
}
