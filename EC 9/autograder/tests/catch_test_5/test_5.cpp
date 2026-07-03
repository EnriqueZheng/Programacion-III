//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include <string>
#include "P5.h"
using namespace std;

static void test_5() {
    string text;
    getline(cin, text);
    cout << boolalpha << is_equation_balanced(text);
}

TEST_CASE("Question #5") {
    execute_test("test_5.in", test_5);
}