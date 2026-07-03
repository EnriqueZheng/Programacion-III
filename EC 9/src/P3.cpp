#include "P3.h"
#include "stack_utec.h"

std::string process_text_by_stack(std::string source) {
    utec::stack<char> s;
    std::string result;
    for (char ch : source) {
        if (ch == '*') {
            if (!s.empty()) {
                result += s.top();
                s.pop();
            }
        } else {
            s.push(ch);
        }
    }
    return result;
}
