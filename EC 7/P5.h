#ifndef PROGRA_III_P5_H
#define PROGRA_III_P5_H
#include <vector>
#include <array>
#include <mutex>
#include <thread>
#include <chrono>

namespace utec {

    enum class tribune { north, south, east, west };

    class stadium {
        int rows_;
        std::array<int, 4> cols_;
        std::array<std::vector<std::vector<bool>>, 4> seats_;
        std::mutex mtx_;

        static int index(tribune t) { return static_cast<int>(t); }

    public:
        stadium(int rows, int north, int south, int east, int west)
            : rows_(rows), cols_{north, south, east, west} {
            for (int t = 0; t < 4; ++t)
                seats_[t].assign(rows_, std::vector<bool>(cols_[t], false));
        }

        bool reserve(tribune t, int row, int col) {
            int ti = index(t);

            if (row < 1 || row > rows_ || col < 1 || col > cols_[ti])
                return false;

            int r = row - 1, c = col - 1;

            {
                std::lock_guard<std::mutex> lock(mtx_);
                if (seats_[ti][r][c])
                    return false;
                seats_[ti][r][c] = true;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            return true;
        }
    };

}
#endif //PROGRA_III_P5_H