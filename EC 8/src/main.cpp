#include <iostream>
#include "../include/Expenses.h"
using namespace std;

int main() {
    ExpenseList expenses{
            {"2026-06-01", "food", "lunch", 18.50},
            {"2026-06-04", "transport", "bus", 3.20},
            {"2026-06-02", "books", "cpp primer", 45.00},
            {"2026-06-03", "food", "dinner", 27.90},
            {"2026-06-05", "books", "algorithms", 38.00}};

    auto by_amount_desc = [](const Expense& a, const Expense& b) {
        return a.amount > b.amount;
    };
    sort_with(expenses, by_amount_desc);

    ExportFunction csv = make_exporter<CsvExporter>();
    ExportFunction json = make_exporter<JsonExporter>();

    cout << "=== CSV ===\n" << csv(expenses);
    cout << "\n=== JSON ===\n" << json(expenses);
    auto decorated =
        AuditedExporter{
            SummaryExporter{
                TextExporter{}}};

    cout << "\n=== TEXT + summary + audit ===\n"
              << decorated.export_expenses(expenses);

    return 0;
}