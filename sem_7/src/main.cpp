#include "bracket_checker.h"
#include "frequency_dict.h"
#include "report_printer.h"
#include "word_splitter.h"

#include <iostream>
#include <iterator>
#include <tuple>

int main() {
    std::cout << "Enter text (Ctrl+D to finish):\n";

    const std::string text((std::istreambuf_iterator<char>(std::cin)), std::istreambuf_iterator<char>());

    const auto [isBalanced, errors] = checkBrackets(text);

    if (isBalanced) {
        std::cout << "Brackets are balanced.\n";
    } else {
        std::cout << "Bracket errors found:\n";
        for (const auto& [line, position, symbol] : errors) {
            std::cout << "line=" << line << ", pos=" << position << ", symbol='" << symbol << "'\n";
        }
    }

    const std::vector<std::string> words = splitIntoWords(text);
    const std::unordered_map<std::string, int> dict = buildFrequencyDict(words);
    printReport(dict, 10);

    return 0;
}
