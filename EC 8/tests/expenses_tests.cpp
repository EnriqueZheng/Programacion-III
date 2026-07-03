#include <cassert>
#include <string>
#include <tuple>

#include "../include/Expenses.h"

static bool contains(const std::string& haystack, const std::string& needle) {
    return haystack.find(needle) != std::string::npos;
}

void test_strategy_sort_by_amount_descending() {
    ExpenseList expenses{
        {"2026-06-01", "food", "lunch", 18.50},
        {"2026-06-02", "transport", "bus", 3.20},
        {"2026-06-03", "books", "cpp", 45.00}};

    auto by_amount = [](const Expense& a, const Expense& b) {
        return a.amount > b.amount;
    };

    sort_with(expenses, by_amount);

    assert(expenses.front().amount == 45.00);
    assert(expenses.back().amount == 3.20);
}

void test_strategy_sort_by_category_then_date() {
    ExpenseList expenses{
        {"2026-06-03", "transport", "bus", 3.20},
        {"2026-06-01", "books", "cpp", 45.00},
        {"2026-06-02", "books", "algorithms", 38.00}};

    auto by_category_then_date = [](const Expense& a, const Expense& b) {
        return std::tie(a.category, a.date) < std::tie(b.category, b.date);
    };

    sort_with(expenses, by_category_then_date);

    assert(expenses[0].category == "books");
    assert(expenses[0].date == "2026-06-01");
    assert(expenses[2].category == "transport");
}

void test_factory_create_csv_exporter() {
    ExpenseList expenses{
        {"2026-06-01", "food", "lunch", 18.50},
        {"2026-06-02", "transport", "bus", 3.20}};

    auto exporter = make_exporter<CsvExporter>();
    auto output = exporter(expenses);

    assert(contains(output, "date,category,detail,amount"));
    assert(contains(output, "food"));
    assert(contains(output, "transport"));
}

void test_factory_create_json_exporter() {
    ExpenseList expenses{
        {"2026-06-01", "food", "lunch", 18.50}};

    auto exporter = make_exporter<JsonExporter>();
    auto output = exporter(expenses);

    assert(contains(output, "\"category\""));
    assert(contains(output, "\"food\""));
    assert(contains(output, "\"amount\""));
}

void test_decorator_audit_preserves_inner_export() {
    ExpenseList expenses{
        {"2026-06-01", "food", "lunch", 18.50},
        {"2026-06-02", "transport", "bus", 3.20}};

    AuditedExporter exporter{CsvExporter{}};
    auto output = exporter.export_expenses(expenses);

    assert(contains(output, "date,category,detail,amount"));
    assert(contains(output, "transport"));
    assert(contains(output, "audit"));
}

void test_decorator_summary_adds_total() {
    ExpenseList expenses{
        {"2026-06-01", "food", "lunch", 18.50},
        {"2026-06-02", "transport", "bus", 3.20}};

    SummaryExporter exporter{TextExporter{}};
    auto output = exporter.export_expenses(expenses);

    assert(contains(output, "food"));
    assert(contains(output, "total"));
    assert(contains(output, "21.7") || contains(output, "21.70"));
}

void test_integration_export_sorted_expenses() {
    ExpenseList expenses{
        {"2026-06-01", "food", "lunch", 18.50},
        {"2026-06-02", "transport", "bus", 3.20},
        {"2026-06-03", "books", "cpp", 45.00}};

    auto by_amount = [](const Expense& a, const Expense& b) {
        return a.amount > b.amount;
    };

    sort_with(expenses, by_amount);

    auto exporter =
        AuditedExporter{
            SummaryExporter{
                CsvExporter{}}};

    auto output = exporter.export_expenses(expenses);

    assert(expenses.front().amount == 45.00);
    assert(contains(output, "date,category,detail,amount"));
    assert(contains(output, "total"));
    assert(contains(output, "audit"));
}

int main() {
    test_strategy_sort_by_amount_descending();
    test_strategy_sort_by_category_then_date();
    test_factory_create_csv_exporter();
    test_factory_create_json_exporter();
    test_decorator_audit_preserves_inner_export();
    test_decorator_summary_adds_total();
    test_integration_export_sorted_expenses();
    return 0;
}