#ifndef EC_8_EXPENSES_H
#define EC_8_EXPENSES_H
#pragma once
#include <algorithm>
#include <concepts>
#include <functional>
#include <iomanip>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>


struct Expense {
    std::string date;
    std::string category;
    std::string detail;
    double amount{};
};

using ExpenseList = std::vector<Expense>;

inline std::string format_amount(double amount) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << amount;
    return oss.str();
}

template <class T>
concept ExpenseExporter =
    requires(T exporter, const ExpenseList& expenses) {
        { exporter.export_expenses(expenses) } -> std::same_as<std::string>;
    };

using ExportFunction = std::function<std::string(const ExpenseList&)>;

template <class R, class Cmp>
concept SortStrategy =
    std::ranges::random_access_range<R> &&
    std::sortable<std::ranges::iterator_t<R>, Cmp>;

void sort_with(auto& values, auto cmp)
    requires SortStrategy<decltype(values), decltype(cmp)>
{
    std::ranges::sort(values, cmp);
}

template <ExpenseExporter E, class... Args>
ExportFunction make_exporter(Args&&... args) {
    return [exporter = E{std::forward<Args>(args)...}](const ExpenseList& expenses) {
        return exporter.export_expenses(expenses);
    };
}

struct CsvExporter {
    static std::string export_expenses(const ExpenseList& expenses) {
        std::string out = "date,category,detail,amount\n";
        for (const auto& e : expenses) {
            out += e.date + "," + e.category + "," + e.detail + "," +
                   format_amount(e.amount) + "\n";
        }
        return out;
    }
};

struct JsonExporter {
    static std::string export_expenses(const ExpenseList& expenses) {
        std::string out = "[\n";
        for (std::size_t i = 0; i < expenses.size(); ++i) {
            const auto& e = expenses[i];
            out += "  {";
            out += R"("date": ")" + e.date + "\", ";
            out += R"("category": ")" + e.category + "\", ";
            out += R"("detail": ")" + e.detail + "\", ";
            out += "\"amount\": " + format_amount(e.amount);
            out += "}";
            if (i + 1 < expenses.size()) out += ",";
            out += "\n";
        }
        out += "]\n";
        return out;
    }
};

struct TextExporter {
    static std::string export_expenses(const ExpenseList& expenses) {
        std::string out;
        for (const auto& e : expenses) {
            out += e.date + " | " + e.category + " | " + e.detail + " | " +
                   format_amount(e.amount) + "\n";
        }
        return out;
    }
};

template <ExpenseExporter Inner>
struct AuditedExporter {
    Inner inner;
    [[nodiscard]] std::string export_expenses(const ExpenseList& expenses) const {
        std::string out = inner.export_expenses(expenses);
        out += "audit: exported " + std::to_string(expenses.size()) +
               " expense(s)\n";
        return out;
    }
};

template <ExpenseExporter Inner>
struct SummaryExporter {
    Inner inner;
    [[nodiscard]] std::string export_expenses(const ExpenseList& expenses) const {
        std::string out = inner.export_expenses(expenses);
        double total = 0.0;
        for (const auto& e : expenses) total += e.amount;
        out += "total: " + format_amount(total) + "\n";
        return out;
    }
};
#endif //EC_8_EXPENSES_H