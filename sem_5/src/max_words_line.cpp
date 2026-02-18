#include "max_words_line.h"
#include "count_words.h"
#include <sstream>

std::string max_words_line(const std::string& text) {
    std::istringstream iss(text);
    std::string line;
    int bestCount = -1;
    std::string bestLine;
    
    while (std::getline(iss, line)) {
        int count = count_words(line);
        if (count > bestCount) {
            bestCount = count;
            bestLine = line;
        }
    }
    return bestLine;
}