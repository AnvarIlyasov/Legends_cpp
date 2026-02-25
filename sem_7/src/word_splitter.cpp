#include "word_splitter.h"
#include "string"
#include "vector"
#include <cctype>

std::vector<std::string> splitIntoWords(const std::string& text) {
    std::vector<std::string> words;
    std::string current;

    for (unsigned char symbol : text) {
        if (std::isalnum(symbol)) {
            current.push_back(static_cast<char>(std::tolower(symbol)));
        } else if (!current.empty()) {
            words.push_back(current);
            current.clear();
        }
    }

    if (!current.empty()) {
        words.push_back(current);
    }

    return words;
}
