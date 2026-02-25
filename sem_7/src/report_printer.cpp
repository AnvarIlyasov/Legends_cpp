#include "report_printer.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

void printReport(const std::unordered_map<std::string, int>& dict, int topN) {
    if (dict.empty()) {
        std::cout << "Dictionary is empty\n";
        return;
    }

    std::vector<std::pair<std::string, int>> words(dict.begin(), dict.end());

    std::sort(words.begin(), words.end(), [](const auto& left, const auto& right) {
        if (left.second != right.second) {
            return left.second > right.second;
        }
        return left.first < right.first;
    });

    const int limit = std::min(topN, static_cast<int>(words.size()));

    std::cout << "\nFREQUENCY DICTIONARY (TOP " << limit << ")\n";
    std::cout << std::left << std::setw(20) << "WORD"
              << " | " << std::right << std::setw(10) << "FREQUENCY" << '\n';

    for (int index = 0; index < limit; ++index) {
        std::cout << std::left << std::setw(20) << words[index].first
                  << " | " << std::right << std::setw(10) << words[index].second << '\n';
    }
}
