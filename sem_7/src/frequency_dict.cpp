#include "frequency_dict.h"

std::unordered_map<std::string, int> buildFrequencyDict(const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> dict;

    for (const std::string& word : words) {
        ++dict[word];
    }

    return dict;
}
