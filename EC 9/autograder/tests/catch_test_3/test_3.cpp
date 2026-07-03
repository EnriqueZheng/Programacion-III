//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include <string>
#include "P3.h"
using namespace std;

static void test_3() {
    string text;
    getline(cin, text);
    cout << process_text_by_stack(text);
}

TEST_CASE("Question #3") {
    execute_test("test_3.in", test_3);
}