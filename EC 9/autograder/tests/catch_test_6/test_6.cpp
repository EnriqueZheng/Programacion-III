//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include <string>
#include "stack_utec.h"
#include <utility>
#include "P6.h"
using namespace std;

namespace test {
    class student_t {
        string name;
        string surname;
        double grade{};
    public:
        student_t() = default;
        student_t(string name, string surname, double  grade):
            name(std::move(name)), surname(surname), grade(grade) {}
        [[nodiscard]] string get_name() const { return name; }
        [[nodiscard]] string get_surname() const { return surname; }
        [[nodiscard]] double get_grade() const { return grade; }
    };
}
static void test_6() {
    utec::stack<test::student_t> s1;
    int n{};
    cin >> n;
    string nombre;
    string apellido;
    double nota;
    while (n-- > 0) {
        cin >> nombre;
        cin >> apellido;
        cin >> nota;
        s1.push(test::student_t{nombre, apellido, nota});
    }
    string name_tobe_found;
    cin >> name_tobe_found;
    auto comp = [=](test::student_t a) -> bool {
        return a.get_name() == name_tobe_found;
    };
    auto a1 = find_in_stack<test::student_t> (s1, comp);

    cout    << a1.get_name() << " "
            << a1.get_surname() << " "
            << a1.get_grade() << endl;
}

TEST_CASE("Question #6") {
    execute_test("test_6.in", test_6);
}
