#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

struct StockData {
    std::string date;
    double Open;
    double High;
    double Low;
    double Close;
    long Volume;
    std::string Name;
};

// Converts string to double safely
double safeStod(const std::string& s) {
    try {
        return std::stod(s);
    } catch (...) {
        return 0.0;
    }
}

// Converts string to long safely
long safeStol(const std::string& s) {
    try {
        return std::stol(s);
    } catch (...) {
        return 0;
    }
}

// Reads the CSV and filters by company name
std::vector<StockData> readCSV(const std::string& filename, const std::string& targetCompany) {
    std::ifstream file(filename);
    std::vector<StockData> stocks;

    std::string line, word;
    getline(file, line); // Skip header

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> row;
        while (getline(ss, word, ',')) {
            row.push_back(word);
        }
        if (row.size() < 7) continue;

        StockData stock;
        stock.date = row[0];
        stock.Open = safeStod(row[1]);
        stock.High = safeStod(row[2]);
        stock.Low = safeStod(row[3]);
        stock.Close = safeStod(row[4]);
        stock.Volume = safeStol(row[5]);
        stock.Name = row[6];

        if (stock.Name == targetCompany) {
            stocks.push_back(stock);
        }
    }

    return stocks;
}

// Displays statistical summary
void displayStatistics(const std::vector<StockData>& stocks) {
    if (stocks.empty()) {
        std::cout << "No data available.\n";
        return;
    }

    double sumClose = 0;
    double highest = stocks[0].Close, lowest = stocks[0].Close;
    long totalVolume = 0;

    for (const auto& s : stocks) {
        sumClose += s.Close;
        highest = std::max(highest, s.Close);
        lowest = std::min(lowest, s.Close);
        totalVolume += s.Volume;
    }

    std::cout << "\n--- Stock Statistics ---\n";
    std::cout << "Total Records: " << stocks.size() << "\n";
    std::cout << "Average Closing Price: " << (sumClose / stocks.size()) << "\n";
    std::cout << "Highest Close: " << highest << "\n";
    std::cout << "Lowest Close: " << lowest << "\n";
    std::cout << "Total Volume: " << totalVolume << "\n";
}

// Filters by date range
void filterByDate(const std::vector<StockData>& stocks, const std::string& start, const std::string& end) {
    std::cout << "\n--- Filtered Data (" << start << " to " << end << ") ---\n";
    for (const auto& s : stocks) {
        if (s.date >= start && s.date <= end) {
            std::cout << s.date << " Close: " << s.Close << "\n";
        }
    }
}

// Shows trend (up/down)
void displayTrend(const std::vector<StockData>& stocks) {
    std::cout << "\n--- Price Trend (Up/Down) ---\n";
    for (size_t i = 1; i < stocks.size(); ++i) {
        std::string trend = (stocks[i].Close > stocks[i - 1].Close) ? "Up" : "Down";
        std::cout << stocks[i].date << ": " << trend << "\n";
    }
}

// ASCII chart of closing prices
void displayAsciiChart(const std::vector<StockData>& stocks) {
    std::cout << "\n--- ASCII Chart for Closing Prices ---\n";
    for (size_t i = 0; i < std::min(size_t(30), stocks.size()); ++i) {
        int bars = static_cast<int>(stocks[i].Close / 5);  // adjust scale as needed
        std::cout << stocks[i].date << " | " << std::string(bars, '#') << " (" << stocks[i].Close << ")\n";
    }
}

int main() {
    std::string filename = "all_stocks_5yr.csv";
    std::string company;
    std::cout << "Enter company name (as in 'Name' column, e.g., AAPL, GOOG): ";
    std::cin >> company;

    std::vector<StockData> stocks = readCSV(filename, company);

    if (stocks.empty()) {
        std::cout << "No records found for company: " << company << "\n";
        return 1;
    }

    displayStatistics(stocks);

    std::string startDate = "2016-01-01";
    std::string endDate = "2016-12-31";
    filterByDate(stocks, startDate, endDate);

    displayTrend(stocks);
    displayAsciiChart(stocks);

    return 0;
}
