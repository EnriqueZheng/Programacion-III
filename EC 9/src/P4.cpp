#include "P4.h"
#include "queue_utec.h"

std::string process_text_by_queue(const std::string& source) {
    utec::queue<char> q;
    std::string result;
    for (char ch : source) {
        if (ch == '*') {
            if (!q.empty()) {
                result += q.front();
                q.pop();
            }
        } else {
            q.push(ch);
        }
    }
    return result;
}
